#include <iostream>
#include <fstream>
#include <lua.hpp>

lua_State* init_lua();

int load_luafile(lua_State* L,char* raw_lua_text);