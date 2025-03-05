#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>
#include <imgui.h>
#include "backend/imgui_impl_opengl3.h"
#include "backend/imgui_impl_sdl3.h"
#include "backend/imgui_impl_opengl3_loader.h"
#include <python3.11/Python.h>

int sdl_main();

bool sdl_update();

void sdl_render();

int sdl_remove();

SDL_Window* window;
SDL_GLContext gl_context;
ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);