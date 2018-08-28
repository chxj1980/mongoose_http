local usermng = class("usermng")

local userDirName = "user"
local userListFileName = "userlist.data"
local userListFilePath = userDirName.."\\"..userListFileName

local DEFAULT_MAX_PLAY_COUNT = 5

function usermng:ctor()
	_MyG.Functions:createDir(userDirName)
	local content = _MyG.Functions:readFile(userListFilePath)

	self.userDataList = {}

	if content ~= nil and content ~= "" then
		local func, err = loadstring(content)
		if func then
			self.userDataList = func()
		else
			print("read userinfo list fail", err)
		end
	end
end

function usermng:isExistUser(userid)
	for i,v in ipairs(self.userDataList) do
		if v.userid == userid then
			return true
		end
	end
	return false
end

function usermng:getUserInfo(userid)
	for i,v in ipairs(self.userDataList) do
		if v.userid == userid then
			return v
		end
	end
end

function usermng:getOrCreateUser(userid)
	for i,v in ipairs(self.userDataList) do
		if v.userid == userid then
			return v
		end
	end
	return self:generateNewUser(userid)
end

function usermng:dumpString()

	local totalCount = 0
	local vipCount = 0

	for i,v in ipairs(self.userDataList) do
		totalCount = totalCount + 1
		if v.maxPlayCount == -1 then
			vipCount = vipCount + 1
		end
	end

	return string.format("totalCount = %d   vipCount = %d   normalCount = %d", totalCount, vipCount, totalCount - vipCount)
end

function usermng:generateNewUser(userid)
	local y, m, d = _MyG.Functions:getCurTime()
	local userinfo = {}
	userinfo["userid"] = userid
	userinfo["registerTime"] = os.date("%Y-%m-%d  %H:%M:%S", os.time())
	userinfo["lastM"] = m
	userinfo["lastD"] = d
	userinfo["maxPlayCount"] = DEFAULT_MAX_PLAY_COUNT
	userinfo["activationCode"] = ""
	userinfo["activationTime"] = ""
	userinfo["playHistory"] = {}
	table.insert(self.userDataList, userinfo)
	return userinfo
end

function usermng:save()
	local content = "local M = "
	content = content.._MyG.Functions:formatTableToString(self.userDataList)
	content = content.."\nreturn M"
	_MyG.Functions:writeFile(userListFilePath, content)
end

-----------------------------------------------------------------------------------------------------------------------

function usermng:request_Login(userid)
	local userinfo = _MyG.UserInfoManager:getOrCreateUser(userid)

	if userinfo.maxPlayCount == -1 then
		return 0, userinfo.maxPlayCount 
	end

	local y, m, d = _MyG.Functions:getCurTime()

	if userinfo.lastM == m and userinfo.lastD == d then
		return #userinfo.playHistory, userinfo.maxPlayCount
	end
	userinfo["lastM"] = m
	userinfo["lastD"] = d
	userinfo["maxPlayCount"] = DEFAULT_MAX_PLAY_COUNT
	userinfo["playHistory"] = {}
	return 0, userinfo.maxPlayCount
end

function usermng:request_Play(userid, movId)
	local userinfo = _MyG.UserInfoManager:getUserInfo(userid)
	if userinfo == nil then
		return
	end

	if userinfo.maxPlayCount == -1 then
		return 0, userinfo.maxPlayCount 
	end

	local y, m, d = _MyG.Functions:getCurTime()

	if userinfo.lastM == m and userinfo.lastD == d then

		local find = false
		for k, v in pairs(userinfo.playHistory) do
			if v == movId then
				find = true
				break
			end
		end

		if not find then
			table.insert(userinfo.playHistory, movId)
		end
		return #userinfo.playHistory, userinfo.maxPlayCount
	end
	userinfo["lastM"] = m
	userinfo["lastD"] = d
	userinfo["maxPlayCount"] = DEFAULT_MAX_PLAY_COUNT
	userinfo["playHistory"] = {}
	table.insert(userinfo.playHistory, movId)
	return 1, userinfo.maxPlayCount
end

function usermng:request_Activation(userid, activationCode)
	local userinfo = _MyG.UserInfoManager:getUserInfo(userid)
	if userinfo == nil then--用户不存在
		return 3, "用户不存在"
	end

	if userinfo.maxPlayCount == -1 then
		return 0, "您已经激活过了"
	end

	local state, codeInfo = _MyG.ActivationCodeMng:isInvalid(activationCode)
	if state == 1 then--已使用
		return 1, "激活码已被使用"
	end
	if state == -1 then--无效码
		return 2, "激活码无效"
	end

	userinfo["maxPlayCount"] = -1
	userinfo["playHistory"] = {}
	userinfo["activationCode"] = activationCode
	userinfo["activationTime"] = os.date("%Y-%m-%d  %H:%M:%S", os.time())

	codeInfo["invalid"] = 1
	codeInfo["useTime"] = userinfo["activationTime"]
	_MyG.ActivationCodeMng:addUseCount()

	return 0, "激活成功", true
end

return usermng