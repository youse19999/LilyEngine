#include "sdl_render.cpp"
int main()
{
	//Lua‚ÉŠÖ”‚ğ“o˜^
	lua_State* L = init_lua();
	register_lua(L);
	
	return 0;
}