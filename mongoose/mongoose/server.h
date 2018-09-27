#pragma once

#include "mongoose.h"
#include <string>
#include <map>
#include <functional>
#include "LuaFunction.h"

enum METHOD
{
	GET,
	PUT,
	POST,
	ALL
};

class server;
typedef std::function<void(server*, mg_connection*, http_message*)> call_func;

class server
{
	static server* server_instance;
public:
	server();
	~server();

	static server* getInstance();
	static void destroy();

	bool start(const std::string& port);
	void stop();

	bool register_call(METHOD method, const std::string& uri, const LuaFunction& call);

	bool register_call(METHOD method, const std::string& uri, const call_func& call);

	void unregister_call(METHOD method, const std::string& uri);

	void send_response(mg_connection *connection, const std::string& response);

	METHOD get_method(http_message *http_req);
	
protected:
	void on_http_event(mg_connection *connection, int event_type, void *event_data);

	void on_http_request(mg_connection *connection, http_message *http_req);

	void clear();

public:
	mg_serve_http_opts m_server_option; // web服务器选项
	mg_mgr* m_mgr;						// 连接管理器

protected:
	std::map<std::string, call_func > m_calls[METHOD::ALL + 1];
	std::map<std::string, LuaFunction* > m_lua_calls[METHOD::ALL + 1];
	bool m_stop;
private:
	static void g_on_http_event(mg_connection *connection, int event_type, void *event_data);
};
