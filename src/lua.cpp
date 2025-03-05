#include "lua.h"

int test_lua() {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	if (luaL_loadstring(L, "print('Hello from Lua!')") || lua_pcall(L, 0, 0, 0))
	{
		std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
		lua_close(L);
		return 1;
	}
	return 0;
}