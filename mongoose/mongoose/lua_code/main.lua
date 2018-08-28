
_MyG = {}

local function main()
	require("lua_code.init")
	svrInstance = server:getInstance()
	if svrInstance == nil then
		print("svrInstance = nil")
	end
	require("lua_code.logic")
	svrInstance:start("8080")
end

__G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    print(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
   -- print(msg)
end
