#include "sdl_render.h"

int sdl_main()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);

	const char* glsl_version = "#version 300 es";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	Uint32 window_flags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIDDEN;
	SDL_Window* window = SDL_CreateWindow("LilyEngine", 1280, 720, window_flags);
	SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1);
	SDL_ShowWindow(window);
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.Fonts->AddFontDefault();
	io.Fonts->Build();
	ImGui::StyleColorsDark();
	ImGui_ImplSDL3_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL3_Init(glsl_version);
	bool show_demo_window = true;
	bool show_another_window = false;
	return 0;
}
int sdl_draw_texture()
{

}
bool sdl_update()
{
	bool quit = false;
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		ImGui_ImplSDL3_ProcessEvent(&event);
		if (event.type == SDL_EVENT_QUIT)
			quit = true;
		if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window))
			quit = true;
	}
	if (SDL_GetWindowFlags(window) & SDL_WINDOW_MINIMIZED)
	{
		SDL_Delay(10);
	}
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();
	SDL_Delay(1);
	return quit;
}
void set_background_color(float r, float g, float b, float a) {
	clear_color = ImVec4(r, g, b, a);
}
void sdl_render() {
	ImGui::Render();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
	return;
}
int sdl_remove()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL3_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DestroyContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
int register_lua(lua_State* L)
{
	lua_pushcfunction(L, sdl_main_lua);
	lua_setglobal(L, "SdlMain");
	lua_pushcfunction(L, sdl_update_lua);
	lua_setglobal(L, "SdlUpdate");
	lua_pushcfunction(L, sdl_render_lua);
	lua_setglobal(L, "SdlRender");
	lua_pushcfunction(L, sdl_remove_lua);
	lua_setglobal(L, "SdlRemove");
	lua_pushcfunction(L, sdl_set_background_color);
	lua_setglobal(L, "SdlSetBackgroundColor");

	load_luafile(L, "lua/entry.lua");
	return 0;
}

int sdl_main_lua(lua_State* L) {
	sdl_main();
	return 0;
}
int sdl_update_lua(lua_State* L) {
	int quit = sdl_update();
	return quit;
}
int sdl_render_lua(lua_State* L) {
	sdl_render();
	return 0;
}
int sdl_remove_lua(lua_State* L) {
	sdl_remove();
	return 0;
}
int sdl_set_background_color(lua_State* L) {
	int r = lua_toboolean(L, 1);
	int g = lua_toboolean(L, 2);
	int b = lua_toboolean(L, 3);
	int a = lua_toboolean(L, 4);
	set_background_color(r, g, b, a);
	return 0;
}