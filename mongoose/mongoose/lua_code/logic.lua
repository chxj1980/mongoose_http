require("lua_code.json")

local function checkAdmin(query_string)
	local username = get_http_var(query_string, "username")
	local password = get_http_var(query_string, "password")
	if username == "fangcheng" and password == "wodemingzi" then
		return true
	end
	return false
end



--------------------------------------------user api--------------------------------------------

svrInstance:register_call(GET, "/api/latestConfig", function(svr, connection, http_msg)

	if _MyG.lastRecordSaveTime == nil then
		_MyG.lastRecordSaveTime = os.time()
	else
		local curTime = os.time()
		if curTime - _MyG.lastRecordSaveTime > 300 then
			local curY, curM, curD = _MyG.Functions:getCurTime()
			curD = tonumber(curD)
			if curD ~= _MyG.Record.day then
				_MyG.Functions:saveRecord()
			end
		end
		_MyG.lastRecordSaveTime = curTime
	end

	_MyG.Record.requestLatestConfigCount = _MyG.Record.requestLatestConfigCount + 1

	local ret = {}

	local curVer = get_http_var(http_msg.query_string, "curVer")
	local uniqueID = get_http_var(http_msg.query_string, "uniqueID")

	if curVer == "" or uniqueID == "" then
		ret.code = 1
		ret.data = "invalid param"
		svr:send_response(connection, json.encode(ret));
		return
	end

	local ver = tonumber(curVer)
	--版本号错误
	if type(ver) ~= "number" then
		ret.code = 1
		ret.data = "invalid version"
		svr:send_response(connection, json.encode(ret));
		return
	end

	--request_Login
	local curPlayCount, maxPlayCount = _MyG.UserInfoManager:request_Login(uniqueID)

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
	ret["curPlayCount"] = curPlayCount
	ret["maxPlayCount"] = maxPlayCount
	svr:send_response(connection, json.encode(ret));	
end)

svrInstance:register_call(GET, "/api/playMov", function(svr, connection, http_msg)

	local ret = {}

	local uniqueID = get_http_var(http_msg.query_string, "uniqueID")
	local movId = get_http_var(http_msg.query_string, "movId")

	if uniqueID == "" or movId == "" then
		ret.code = 1
		ret.msg = "invalid param"
		svr:send_response(connection, json.encode(ret));
		return
	end

	local curPlayCount, maxPlayCount = _MyG.UserInfoManager:request_Play(uniqueID, movId)
	if curPlayCount == nil or maxPlayCount == nil then
		ret.code = 2
		ret.msg = "invalid user"
		svr:send_response(connection, json.encode(ret));
		return
	end
	ret.code = 0
	ret["curPlayCount"] = curPlayCount
	ret["maxPlayCount"] = maxPlayCount
	svr:send_response(connection, json.encode(ret));
end)

svrInstance:register_call(GET, "/api/Activation", function(svr, connection, http_msg)

	local ret = {}

	local uniqueID = get_http_var(http_msg.query_string, "uniqueID")
	local code = get_http_var(http_msg.query_string, "code")

	if uniqueID == "" or code == "" then
		ret.code = 1
		ret.msg = "invalid param"
		svr:send_response(connection, json.encode(ret));
		return
	end
	local needsave = false
	ret.code, ret.msg, needsave = _MyG.UserInfoManager:request_Activation(uniqueID, code)

	svr:send_response(connection, json.encode(ret))

	if needsave then
		_MyG.UserInfoManager:save()
		_MyG.ActivationCodeMng:save()
	end
end)


--------------------------------------------admin--------------------------------------------

svrInstance:register_call(GET, "/getActivationCode", function(svr, connection, http_msg)
	if checkAdmin(http_msg.query_string) then
		local list, newCount = _MyG.ActivationCodeMng:getValidCode(10)
		if newCount > 0 then
			_MyG.ActivationCodeMng:save()
		end
		svr:send_response(connection, json.encode(list));
		return
	end	
	svr:send_response(connection, "ERROR Incorrect username or password");
end)

svrInstance:register_call(GET, "/saveCode", function(svr, connection, http_msg)
	if checkAdmin(http_msg.query_string) then
		_MyG.ActivationCodeMng:save()
		svr:send_response(connection, "save success");
		return
	end	
	svr:send_response(connection, "ERROR Incorrect username or password");
end)

svrInstance:register_call(GET, "/saveUserList", function(svr, connection, http_msg)
	if checkAdmin(http_msg.query_string) then
		_MyG.UserInfoManager:save()
		svr:send_response(connection, "save success");
		return
	end	
	svr:send_response(connection, "ERROR Incorrect username or password");
end)

svrInstance:register_call(GET, "/stop", function(svr, connection, http_msg)
	if checkAdmin(http_msg.query_string) then
		_MyG.Functions:saveRecord()
		_MyG.UserInfoManager:save()
		_MyG.ActivationCodeMng:save()
		svrInstance:stop()
		return
	end	
	svr:send_response(connection, "ERROR Incorrect username or password");
end)

svrInstance:register_call(GET, "/adminHelp", function(svr, connection, http_msg)
	local ret = {"getRecord", "updateConfig", "getConfig", "getActivationCode", "saveCode", "saveUserList", "getUserDump"}
	svr:send_response(connection, json.encode(ret));
end)

svrInstance:register_call(GET, "/getUserDump", function(svr, connection, http_msg)
	local ret = {}
	if checkAdmin(http_msg.query_string) then
		ret.code = 0
		ret.data = _MyG.UserInfoManager:dumpString()
	else
		ret.code = 1
		ret.data = "ERROR Incorrect username or password"
	end
	svr:send_response(connection, json.encode(ret));
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
		local read_ret = _MyG.Functions:readConfig()
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

_MyG.Functions:init()
_MyG.Functions:readRecord()
_MyG.Functions:readConfig()