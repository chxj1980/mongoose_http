require "lfs"

local Functions = {}

local record_dir_name = "record"

function Functions:init()
    local rootpath = lfs.currentdir()

    local find = false

    for entry in lfs.dir(rootpath) do  
        if entry ~= '.' and entry ~= '..' then  
            local path = rootpath .. '\\' .. entry  
            local attr = lfs.attributes(path) 
  
            if attr.mode == 'directory' and entry == record_dir_name then
                find = true
                break
            end  
        end  
    end

    if not find then
        local path = rootpath .. '\\' .. record_dir_name
        if not lfs.mkdir(path) then
            print("create", record_dir_name, "fail")
        end
    end
end

function Functions:formatTableToString(...)
    local s = ""
    local function cout(data,Count)
        if type(data) ~= "nil" then

            if type(data) == "string" then
                s = s.."\""..data.."\""
            elseif type(data) == "table" then
                s = s.." {\n"--table
                for k,v in pairs(data) do
                    if type(v) ~= "nil" then
                        if Count > 0 then
                            for i =1,Count do
                                s = s.."\t"
                            end
                        end
                        if type(k) == "number" then
                            s = s.."["..k.."]".." = "
                        else
                            s = s.."[\""..k.."\"]".." = "
                        end
                        cout(v,Count+1)
                        s = s..",\n"
                    end
                end
                s = string.sub(s,1,-3)
                s = s.."\n"
                if Count-1 > 0 then
                    for i =1,Count-1 do
                        s = s.."\t"
                    end
                end
                s = s.."}"
            elseif type(data) == "boolean" then
                if data == true then
                    s = s..tostring(data)--"真"
                elseif data == false then
                    s = s..tostring(data)--"假"
                end
            else
                s = s..tostring(data)
            end
        end
    end
    local tab = {...}
    for i = 1, #tab do
        cout(tab[i],1)
        if tab[i+1] then
            s = s..","
        end
    end
    return s
end

function Functions:readFile(fileName)
    local f = assert(io.open(fileName,'r'))
    local content = f:read('*all')
    f:close()
    return content
end

function Functions:writeFile(fileName,content)
    local f = assert(io.open(fileName,'w'))
    f:write(content)
    f:close()
end

function Functions:readConfig()
	local content = self:readFile("list.config")
	local func, err = loadstring(content)
	if func then
		_MyG.Config = func()
	else
		print("read config fail", err)
		return err
	end
end

function Functions:saveConfig()
end

function Functions:createNewRecord(isReadRecordFail)
    local y, m, d = self:getCurTime()

    _MyG.Record = {}
    _MyG.Record.year = tonumber(y)
    _MyG.Record.month = tonumber(m)
    _MyG.Record.day = tonumber(d)
    _MyG.Record.createTime = os.date("%Y-%m-%d  %H:%M:%S", os.time())
    _MyG.Record.saveTime = ""
    _MyG.Record.requestLatestConfigCount = 0
    _MyG.Record.requestLatestConfigSucCount = 0
    _MyG.Record.isReadRecordFail = isReadRecordFail
end

function Functions:readRecord()
    local fileName = self:recordFileName()
    local f = io.open(fileName,'r')
    if f == nil then
        self:createNewRecord()
        return
    end

    local content = f:read('*all')
    f:close()

    local func, err = loadstring(content)
    if func then
        _MyG.Record = func()
    else
        print("read record fail", err)
        self:createNewRecord(true)
    end
end

function Functions:recordFileName()
    local formatstr = record_dir_name.."/%Y-%m-%d.data"
    return os.date(formatstr, os.time())
end

function Functions:saveRecord()
    _MyG.Record.saveTime = os.date("%Y-%m-%d  %H:%M:%S", os.time())

    local str = "local M = "
    str = str..self:formatTableToString(_MyG.Record)
    str = str.."\nreturn M"

    local formatstr = record_dir_name.."/%d-%02d-%02d.data"
    local fileName = string.format(formatstr, _MyG.Record.year, _MyG.Record.month, _MyG.Record.day)
    self:writeFile(fileName, str)

    self:createNewRecord()
end

function Functions:getCurTime()
    local str = os.date("%Y%m%d%H%M%S", os.time())
    if #str == 14 then
        local index = 1

        local year = string.sub(str, index, index + 3)
        index = index + 4

        local month = string.sub(str, index, index + 1)
        index = index + 2

        local day = string.sub(str, index, index + 1)
        return year, month, day
    end
    local time = os.time()
    local year = os.date("%Y", time)
    local month = os.date("%m", time)
    local day = os.date("%d", time)
    return year, month, day
end




return Functions