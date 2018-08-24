/*
** Lua binding: run
** Generated automatically by tolua++-1.0.92 on Thu Aug 23 15:50:29 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"
#include "../tolua_fix.h"
#include <string>

/* Exported function */
TOLUA_API int  tolua_run_open (lua_State* tolua_S);

#include "../tools.h"
#include "../server.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_server (lua_State* tolua_S)
{
 server* self = (server*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_http_msg (lua_State* tolua_S)
{
 http_msg* self = (http_msg*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"http_msg");
 tolua_usertype(tolua_S,"http_message");
 tolua_usertype(tolua_S,"mg_connection");
 
 tolua_usertype(tolua_S,"server");
}

/* method: new of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_run_http_msg_new00
static int tolua_run_http_msg_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"http_msg",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const http_message",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const http_message* msg = ((const http_message*)  tolua_tousertype(tolua_S,2,0));
  {
   http_msg* tolua_ret = (http_msg*)  Mtolua_new((http_msg)(*msg));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"http_msg");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_run_http_msg_new00_local
static int tolua_run_http_msg_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"http_msg",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const http_message",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const http_message* msg = ((const http_message*)  tolua_tousertype(tolua_S,2,0));
  {
   http_msg* tolua_ret = (http_msg*)  Mtolua_new((http_msg)(*msg));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"http_msg");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: message of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_message
static int tolua_get_http_msg_message(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'message'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->message);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: message of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_message
static int tolua_set_http_msg_message(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'message'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->message = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: body of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_body
static int tolua_get_http_msg_body(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->body);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: body of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_body
static int tolua_set_http_msg_body(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'body'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->body = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: method of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_method
static int tolua_get_http_msg_method(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'method'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->method);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: method of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_method
static int tolua_set_http_msg_method(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'method'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->method = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: uri of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_uri
static int tolua_get_http_msg_uri(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uri'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->uri);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: uri of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_uri
static int tolua_set_http_msg_uri(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'uri'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->uri = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: proto of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_proto
static int tolua_get_http_msg_proto(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'proto'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->proto);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: proto of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_proto
static int tolua_set_http_msg_proto(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'proto'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->proto = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resp_code of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_resp_code
static int tolua_get_http_msg_resp_code(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resp_code'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->resp_code);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resp_code of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_resp_code
static int tolua_set_http_msg_resp_code(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resp_code'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resp_code = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: resp_status_msg of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_resp_status_msg
static int tolua_get_http_msg_resp_status_msg(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resp_status_msg'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->resp_status_msg);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: resp_status_msg of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_resp_status_msg
static int tolua_set_http_msg_resp_status_msg(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'resp_status_msg'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->resp_status_msg = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: query_string of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_http_msg_query_string
static int tolua_get_http_msg_query_string(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'query_string'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->query_string);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: query_string of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_http_msg_query_string
static int tolua_set_http_msg_query_string(lua_State* tolua_S)
{
  http_msg* self = (http_msg*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'query_string'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->query_string = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: header_names of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_run_http_msg_header_names
static int tolua_get_run_http_msg_header_names(lua_State* tolua_S)
{
 int tolua_index;
  http_msg* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (http_msg*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MG_MAX_HTTP_HEADERS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushcppstring(tolua_S,(const char*)self->header_names[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: header_names of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_run_http_msg_header_names
static int tolua_set_run_http_msg_header_names(lua_State* tolua_S)
{
 int tolua_index;
  http_msg* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (http_msg*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MG_MAX_HTTP_HEADERS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->header_names[tolua_index] = ((std::string)  tolua_tocppstring(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: header_values of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_get_run_http_msg_header_values
static int tolua_get_run_http_msg_header_values(lua_State* tolua_S)
{
 int tolua_index;
  http_msg* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (http_msg*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MG_MAX_HTTP_HEADERS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushcppstring(tolua_S,(const char*)self->header_values[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: header_values of class  http_msg */
#ifndef TOLUA_DISABLE_tolua_set_run_http_msg_header_values
static int tolua_set_run_http_msg_header_values(lua_State* tolua_S)
{
 int tolua_index;
  http_msg* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (http_msg*)  lua_touserdata(tolua_S,-1);
#ifndef TOLUA_RELEASE
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifndef TOLUA_RELEASE
 if (tolua_index<0 || tolua_index>=MG_MAX_HTTP_HEADERS)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->header_values[tolua_index] = ((std::string)  tolua_tocppstring(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: print_http_message */
#ifndef TOLUA_DISABLE_tolua_run_print_http_message00
static int tolua_run_print_http_message00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"http_message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  http_message* msg = ((http_message*)  tolua_tousertype(tolua_S,1,0));
  {
   print_http_message(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'print_http_message'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: get_http_var */
#ifndef TOLUA_DISABLE_tolua_run_get_http_var00
static int tolua_run_get_http_var00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const std::string buff = ((const std::string)  tolua_tocppstring(tolua_S,1,0));
  const std::string name = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  get_http_var(buff,name);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)buff);
   tolua_pushcppstring(tolua_S,(const char*)name);
  }
 }
 return 3;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_http_var'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_new00
static int tolua_run_server_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   server* tolua_ret = (server*)  Mtolua_new((server)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"server");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_new00_local
static int tolua_run_server_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   server* tolua_ret = (server*)  Mtolua_new((server)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"server");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_delete00
static int tolua_run_server_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_getInstance00
static int tolua_run_server_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   server* tolua_ret = (server*)  server::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"server");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: destroy of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_destroy00
static int tolua_run_server_destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   server::destroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: start of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_start00
static int tolua_run_server_start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
  const std::string port = ((const std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'start'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->start(port);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)port);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: stop of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_stop00
static int tolua_run_server_stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'stop'", NULL);
#endif
  {
   self->stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: register_call of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_register_call00
static int tolua_run_server_register_call00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !toluafix_isfunction(tolua_S,4,"LuaFunction",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
  METHOD method = ((METHOD) (int)  tolua_tonumber(tolua_S,2,0));
  const std::string uri = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
  LuaFunction call = (  LuaFunction(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'register_call'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->register_call(method,uri,call);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
   tolua_pushcppstring(tolua_S,(const char*)uri);
  }
 }
 return 2;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'register_call'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: unregister_call of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_unregister_call00
static int tolua_run_server_unregister_call00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
  METHOD method = ((METHOD) (int)  tolua_tonumber(tolua_S,2,0));
  const std::string uri = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'unregister_call'", NULL);
#endif
  {
   self->unregister_call(method,uri);
   tolua_pushcppstring(tolua_S,(const char*)uri);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'unregister_call'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: send_response of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_send_response00
static int tolua_run_server_send_response00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"mg_connection",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
  mg_connection* connection = ((mg_connection*)  tolua_tousertype(tolua_S,2,0));
  const std::string response = ((const std::string)  tolua_tocppstring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'send_response'", NULL);
#endif
  {
   self->send_response(connection,response);
   tolua_pushcppstring(tolua_S,(const char*)response);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'send_response'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get_method of class  server */
#ifndef TOLUA_DISABLE_tolua_run_server_get_method00
static int tolua_run_server_get_method00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"server",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"http_message",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  server* self = (server*)  tolua_tousertype(tolua_S,1,0);
  http_message* http_req = ((http_message*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get_method'", NULL);
#endif
  {
   METHOD tolua_ret = (METHOD)  self->get_method(http_req);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get_method'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_run_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"mg_connection","mg_connection","",NULL);
  tolua_beginmodule(tolua_S,"mg_connection");
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"http_message","http_message","",NULL);
  tolua_beginmodule(tolua_S,"http_message");
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"http_msg","http_msg","",tolua_collect_http_msg);
  #else
  tolua_cclass(tolua_S,"http_msg","http_msg","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"http_msg");
   tolua_function(tolua_S,"new",tolua_run_http_msg_new00);
   tolua_function(tolua_S,"new_local",tolua_run_http_msg_new00_local);
   tolua_function(tolua_S,".call",tolua_run_http_msg_new00_local);
   tolua_variable(tolua_S,"message",tolua_get_http_msg_message,tolua_set_http_msg_message);
   tolua_variable(tolua_S,"body",tolua_get_http_msg_body,tolua_set_http_msg_body);
   tolua_variable(tolua_S,"method",tolua_get_http_msg_method,tolua_set_http_msg_method);
   tolua_variable(tolua_S,"uri",tolua_get_http_msg_uri,tolua_set_http_msg_uri);
   tolua_variable(tolua_S,"proto",tolua_get_http_msg_proto,tolua_set_http_msg_proto);
   tolua_variable(tolua_S,"resp_code",tolua_get_http_msg_resp_code,tolua_set_http_msg_resp_code);
   tolua_variable(tolua_S,"resp_status_msg",tolua_get_http_msg_resp_status_msg,tolua_set_http_msg_resp_status_msg);
   tolua_variable(tolua_S,"query_string",tolua_get_http_msg_query_string,tolua_set_http_msg_query_string);
   tolua_array(tolua_S,"header_names",tolua_get_run_http_msg_header_names,tolua_set_run_http_msg_header_names);
   tolua_array(tolua_S,"header_values",tolua_get_run_http_msg_header_values,tolua_set_run_http_msg_header_values);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"print_http_message",tolua_run_print_http_message00);
  tolua_function(tolua_S,"get_http_var",tolua_run_get_http_var00);
  tolua_constant(tolua_S,"GET",GET);
  tolua_constant(tolua_S,"PUT",PUT);
  tolua_constant(tolua_S,"POST",POST);
  tolua_constant(tolua_S,"ALL",ALL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"server","server","",tolua_collect_server);
  #else
  tolua_cclass(tolua_S,"server","server","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"server");
   tolua_function(tolua_S,"new",tolua_run_server_new00);
   tolua_function(tolua_S,"new_local",tolua_run_server_new00_local);
   tolua_function(tolua_S,".call",tolua_run_server_new00_local);
   tolua_function(tolua_S,"delete",tolua_run_server_delete00);
   tolua_function(tolua_S,"getInstance",tolua_run_server_getInstance00);
   tolua_function(tolua_S,"destroy",tolua_run_server_destroy00);
   tolua_function(tolua_S,"start",tolua_run_server_start00);
   tolua_function(tolua_S,"stop",tolua_run_server_stop00);
   tolua_function(tolua_S,"register_call",tolua_run_server_register_call00);
   tolua_function(tolua_S,"unregister_call",tolua_run_server_unregister_call00);
   tolua_function(tolua_S,"send_response",tolua_run_server_send_response00);
   tolua_function(tolua_S,"get_method",tolua_run_server_get_method00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_run (lua_State* tolua_S) {
 return tolua_run_open(tolua_S);
};
#endif

