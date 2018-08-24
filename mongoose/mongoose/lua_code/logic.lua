require("lua_code.json")


local Functions = require("lua_code.functions")

local function checkAdmin(query_string)
	local username = get_http_var(query_string, "username")
	local password = get_http_var(query_string, "password")
	if username == "fangcheng" and password == "wodemingzi" then
		return true
	end
	return false
end


svrInstance:register_call(GET, "/api/latestConfig", function(svr, connection, http_msg)

	if _MyG.lastRecordSaveTime == nil then
		_MyG.lastRecordSaveTime = os.time()
	else
		local curTime = os.time()
		if curTime - _MyG.lastRecordSaveTime > 300 then
			local curY, curM, curD = Functions:getCurTime()
			curD = tonumber(curD)
			if curD ~= _MyG.Record.day then
				Functions:saveRecord()
			end
		end
		_MyG.lastRecordSaveTime = curTime
	end

	_MyG.Record.requestLatestConfigCount = _MyG.Record.requestLatestConfigCount + 1

	local curVer = get_http_var(http_msg.query_string, "curVer")

	local ret = {}
	local ver = tonumber(curVer)
	--版本号错误
	if type(ver) ~= "number" then
		ret.code = 1
		ret.data = "invalid version"
		svr:send_response(connection, json.encode(ret));
		return
	end

	_MyG.Record.requestLatestConfigSucCount = _MyG.Record.requestLatestConfigSucCount + 1

	--需要更新
	if ver ~= _MyG.Config.curVersion then
		ret.code = 0
		ret.data = _MyG.Config
	--已经是最新 不需要更新
	else
		ret.code = 2
		ret.data = ""
	end
	svr:send_response(connection, json.encode(ret));	
end)

svrInstance:register_call(GET, "/stop", function(svr, connection, http_msg)
	if checkAdmin(http_msg.query_string) then
		Functions:saveRecord()
		svrInstance:stop()
		return
	end	
	svr:send_response(connection, "ERROR Incorrect username or password");
end)

svrInstance:register_call(GET, "/getRecord", function(svr, connection, http_msg)
	local ret = {}
	if checkAdmin(http_msg.query_string) then
		ret.code = 0
		ret.data = _MyG.Record
	else
		ret.code = 1
		ret.data = "ERROR Incorrect username or password"
	end
	svr:send_response(connection, json.encode(ret));
end)

svrInstance:register_call(GET, "/updateConfig", function(svr, connection, http_msg)
	local ret = {}
	if checkAdmin(http_msg.query_string) then
		local read_ret = Functions:readConfig()
		if read_ret == nil then
			ret.code = 0
			ret.data = _MyG.Config
		else
			ret.code = 2
			ret.data = read_ret
		end
	else
		ret.code = 1
		ret.data = "ERROR Incorrect username or password"
	end

	svr:send_response(connection, json.encode(ret));
end)

svrInstance:register_call(GET, "/getConfig", function(svr, connection, http_msg)
	local ret = {}
	if checkAdmin(http_msg.query_string) then
			ret.code = 0
			ret.data = json.encode(_MyG.Config)
	else
		ret.code = 1
		ret.data = "ERROR Incorrect username or password"
	end
	svr:send_response(connection, json.encode(ret));
end)

Functions:init()
Functions:readRecord()
Functions:readConfig()


