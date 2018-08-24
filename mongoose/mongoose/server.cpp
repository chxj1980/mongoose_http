#include "server.h"
#include "tools.h"

static const char* method_name[METHOD::ALL] = {
	"GET",
	"PUT",
	"POST",
};

server* server::server_instance = NULL;

server* server::getInstance()
{
	if (server_instance == NULL)
	{
		server_instance = new server();
	}
	return server_instance;
}

void server::destroy()
{
	if (server_instance)
	{
		delete server_instance;
		server_instance = NULL;
	}
}

server::server()
{
	m_stop = true;
	m_mgr = NULL;
}

server::~server()
{
	clear();
}

bool server::start(const std::string& port)
{
	memset(&m_server_option, 0, sizeof(m_server_option));
	m_server_option.enable_directory_listing = "yes";
	m_server_option.document_root = "./web";

	m_mgr = (mg_mgr*)malloc(sizeof(mg_mgr));
	mg_mgr_init(m_mgr, NULL);
	mg_connection *connection = mg_bind(m_mgr, port.c_str(), g_on_http_event);
	
	if (connection == NULL)
		return false;

	connection->user_data = this;
	mg_set_protocol_http_websocket(connection);

	printf("starting http server at port: %s\n", port.c_str());
	m_stop = false;

	while (!m_stop)
	{
		// ms
		mg_mgr_poll(m_mgr, 100);
	}
	clear();
	return true;
}

void server::stop()
{
	m_stop = true;
}

void server::clear()
{
	m_stop = true;
	if (m_mgr)
	{
		mg_mgr_free(m_mgr);
		free(m_mgr);
		m_mgr = NULL;
	}
	for (int i = 0; i <= METHOD::ALL; ++i)
	{
		for (auto it = m_lua_calls[i].begin(); it != m_lua_calls[i].end(); ++it)
		{
			delete it->second;
		}
		m_lua_calls[i].clear();
	}
	for (int i = 0; i <= METHOD::ALL; ++i)
	{
		m_calls[i].clear();
	}
}

bool server::register_call(METHOD method, const std::string& uri, const LuaFunction& call)
{
	LuaFunction* pfunc = new LuaFunction(call);

	bool ret = register_call(method, uri, [=](server* svr, mg_connection* connection, http_message* http_req) {
		http_msg* msg = new http_msg(http_req);
		pfunc->ppush();
		pfunc->pushusertype(svr, "server");
		pfunc->pushusertype(connection, "mg_connection");
		pfunc->pushusertype(msg, "http_msg");
		pfunc->pcall();
		delete msg;
	});

	if (ret)
	{
		m_lua_calls[method].emplace(uri, pfunc);
	}
	else
	{
		delete pfunc;
	}
	return ret;
}

bool server::register_call(METHOD method, const std::string& uri, const call_func& call)
{
	if (method < 0 || method > METHOD::ALL)
	{
		return false;
	}
	std::map<std::string, call_func >* pcalls = &m_calls[method];
	auto it = pcalls->find(uri);
	if (it == pcalls->end())
	{
		pcalls->emplace(uri, call);
		return true;
	}
	return false;
}

void server::unregister_call(METHOD method, const std::string& uri)
{
	if (method < 0 || method > METHOD::ALL)
	{
		return;
	}
	std::map<std::string, call_func >* pcalls = &m_calls[method];
	auto it = pcalls->find(uri);
	if (it != pcalls->end())
	{
		pcalls->erase(it);
		auto lua_it = m_lua_calls[method].find(uri);
		if (lua_it != m_lua_calls[method].end())
		{
			delete lua_it->second;
			m_lua_calls[method].erase(lua_it);
		}
	}
}

void server::send_response(mg_connection *connection, const std::string& response)
{
	// 必须先发送header
	mg_printf(connection, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
	
	if (!response.empty())
	{
		mg_printf_http_chunk(connection, response.c_str());
	}
	// 发送空白字符快，结束当前响应
	mg_send_http_chunk(connection, "", 0);
}

void server::on_http_event(mg_connection *connection, int event_type, void *event_data)
{
	http_message *http_req = (http_message *)event_data;
	switch (event_type)
	{
	case MG_EV_HTTP_REQUEST:
	{
		on_http_request(connection, http_req);
	}
		break;
	default:
		break;
	}
}

METHOD server::get_method(http_message *http_req)
{
	METHOD out = METHOD::ALL;
	for (int i = 0; i < METHOD::ALL; ++i)
	{
		if (mg_vcmp(&http_req->method, method_name[i]) == 0)
		{
			out = (METHOD)i;
			break;;
		}
	}
	return out;
}

void server::on_http_request(mg_connection *connection, http_message *http_req)
{
	//std::string req_str = std::string(http_req->message.p, http_req->message.len);
	//printf("got request: %s\n", req_str.c_str());

	std::string uri = std::string(http_req->uri.p, http_req->uri.len);
	std::map<std::string, call_func >* pcalls = NULL;
	std::map<std::string, call_func >::iterator it;

	METHOD method = get_method(http_req);

	if (method != METHOD::ALL)
	{
		pcalls = &m_calls[method];
		it = pcalls->find(uri);
		if (it != pcalls->end())
		{
			it->second(this, connection, http_req);
			return;
		}
		method = METHOD::ALL;
	}
	pcalls = &m_calls[method];
	it = pcalls->find(uri);
	if (it != pcalls->end())
	{
		it->second(this, connection, http_req);
		return;
	}

	mg_printf(
		connection,
		"%s",
		"HTTP/1.1 501 Not Implemented\r\n"
		"Content-Length: 0\r\n\r\n");
}


//////////////////////////////////////////////////////////////////////////
void server::g_on_http_event(mg_connection *connection, int event_type, void *event_data)
{
	server* svr = (server*)connection->user_data;
	svr->on_http_event(connection, event_type, event_data);
}

