local activationCodeMng = class("activationCodeMng")



local codeDirName = "code"
local codeListFileName = "codelist.data"
local codeListFilePath = codeDirName.."\\"..codeListFileName

local DEFAULT_MAX_PLAY_COUNT = 5

function activationCodeMng:ctor()
	_MyG.Functions:createDir(codeDirName)
	local content = _MyG.Functions:readFile(codeListFilePath)

	self.codeDataList = {}
	if content ~= nil and content ~= "" then
		local func, err = loadstring(content)
		if func then
			self.codeDataList = func()
		else
			print("read code list fail", err)
			self.codeDataList.curIndex = 1
			self.codeDataList.useCount = 0
		end
	else
		self.codeDataList.curIndex = 1
		self.codeDataList.useCount = 0
	end
end

--是否是无效码
function activationCodeMng:isInvalid(code)
	for k,v in ipairs(self.codeDataList) do
		if v.code == code then
			return v.invalid, v
		end
	end
	return -1
end

function activationCodeMng:generateNewCode()

	local randcode = create_activ_code(self.codeDataList.curIndex)

	self.codeDataList.curIndex = self.codeDataList.curIndex + 1

	if self:isInvalid(randcode) ~= -1 then
		return self:generateNewCode()
	end

	local codedata = {}
	codedata["code"] = randcode
	codedata["invalid"] = 0
	codedata["type"] = 0
	codedata["useTime"] = ""
	table.insert(self.codeDataList, codedata)
	return codedata
end

function activationCodeMng:addUseCount()
	self.codeDataList.useCount = self.codeDataList.useCount + 1
end

function activationCodeMng:getValidCode(count)
	if count == nil then
		count = 10
	end
	if count > 20 then
		count = 10
	end

	local codelist = {}
	local curCount = 0
	for k,v in ipairs(self.codeDataList) do
		if v.invalid == 0 then
			curCount = curCount + 1
			codelist[curCount] = v.code
		end
	end
	
	local newCount = 0
	for i = curCount, count do
		newCount = newCount + 1
		curCount = curCount + 1
		local codedata = self:generateNewCode()
		codelist[curCount] = codedata.code
	end
	return codelist, newCount
end

function activationCodeMng:save()
	local content = "local M = "
	content = content.._MyG.Functions:formatTableToString(self.codeDataList)
	content = content.."\nreturn M"
	_MyG.Functions:writeFile(codeListFilePath, content)
end

return activationCodeMng