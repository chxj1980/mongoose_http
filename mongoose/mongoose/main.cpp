#include <iostream>
#include "server.h"
#include "tools.h"

extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "lua-module/lfs/lfs.h"
}
#include "lua-module/mongoose_tolua.h"


void server_log(const std::string& logstr)
{
	FILE* fp = fopen("local.log", "ab+");
	if (fp)
	{
		auto curtime = time(NULL);
		tm* localt = localtime(&curtime);

		static char timebuf[128];
		sprintf(timebuf, "[%d %02d-%02d %02d:%02d:%02d]\t", localt->tm_year + 1900, localt->tm_mon + 1, localt->tm_mday, localt->tm_hour, localt->tm_min, localt->tm_sec);

		std::string save_str = timebuf;
		save_str.append(logstr);
		save_str.append("\n");
		fwrite(save_str.c_str(), 1, save_str.size(), fp);
		fclose(fp);
	}
}

int main(int argc, char *argv[])
{
	server_log("start server...");
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	tolua_run_open(L);
	luaopen_lfs(L);
	
	server::getInstance();
	luaL_dofile(L, "lua_code/main.lua");
	server::destroy();

	server_log("close server...");
	lua_close(L);


	//server* pserver = new server();

	////index.html
	//pserver->register_call(ALL, "/", [](server* svr, mg_connection* connection, http_message* http_req) 
	//{
	//	mg_serve_http(connection, http_req, svr->m_server_option);
	//});

	//pserver->register_call(POST, "/api/sum", [](server* svr, mg_connection* connection, http_message* http_req)
	//{
	//	// 简单post请求，加法运算测试
	//	char n1[100], n2[100];
	//	double result;

	//	/* Get form variables */
	//	mg_get_http_var(&http_req->body, "n1", n1, sizeof(n1));
	//	mg_get_http_var(&http_req->body, "n2", n2, sizeof(n2));

	//	result = strtod(n1, NULL) + strtod(n2, NULL);
	//	char szBuf[64];
	//	sprintf(szBuf, "{ \"result\": %g }", result);
	//	svr->send_response(connection, szBuf);
	//});

	//pserver->register_call(GET, "/api/hello", [](server* svr, mg_connection* connection, http_message* http_req)
	//{
	//	svr->send_response(connection, "welcome to httpserver");
	//});

	//pserver->register_call(ALL, "/api/print", [](server* svr, mg_connection* connection, http_message* http_req)
	//{
	//	print_http_message(http_req);
	//	svr->send_response(connection, "");
	//});

	//pserver->register_call(GET, "/api/close", [](server* svr, mg_connection* connection, http_message* http_req)
	//{
	//	//print_http_message(http_req);

	//	char szName[100], szPassword[100];
	//	mg_get_http_var(&http_req->query_string, "name", szName, sizeof(szName));
	//	mg_get_http_var(&http_req->query_string, "ps", szPassword, sizeof(szPassword));
	//	if (strcmp(szName, "fangcheng") == 0 && strcmp(szPassword, "fangcheng") == 0)
	//	{
	//		svr->stop();
	//	}
	//});

	//pserver->start("8080");
	//delete pserver;
	//printf("server close...\n");
	//system("pause");
	return 0;
}


