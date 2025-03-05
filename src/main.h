#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <imgui.h>
#include "backend/imgui_impl_opengl3.h"
#include "backend/imgui_impl_sdl3.h"
#include "backend/imgui_impl_opengl3_loader.h"
#include <python3.11/Python.h>
#include "lua_exec.h"

SDL_Window* window;
SDL_GLContext gl_context;
ImVec4 clear_color = ImVec4(0, 0, 0, 0);

int sdl_main();

bool sdl_update();

void sdl_render();

int sdl_remove();


//Lua

int sdl_main_lua(lua_State* L) {
	sdl_main();
	return 0;
}
int sdl_update_lua(lua_State* L) {
	sdl_update();
	return 0;
}
int sdl_render_lua(lua_State* L) {
	sdl_render();
	return 0;
}
int sdl_remove_lua(lua_State* L) {
	sdl_remove();
	return 0;
}