#include "lua_exec.h"

using namespace std;
lua_State* init_lua()
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	return L;
}
int load_luafile(lua_State* L,char* path)
{
	if (luaL_loadfile(L, path) || lua_pcall(L, 0, 0, 0))
	{
		std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
		lua_close(L);
		return 1;
	}
	return 0;
}
