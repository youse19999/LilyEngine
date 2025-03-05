#include "lua.h"

using namespace std;

int load_luafile(char* path)
{
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	if (luaL_loadfile(L, path) || lua_pcall(L, 0, 0, 0))
	{
		std::cerr << "Lua error: " << lua_tostring(L, -1) << std::endl;
		lua_close(L);
		return 1;
	}
	return 0;
}
