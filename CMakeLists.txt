cmake_minimum_required(VERSION 3.20)

project(LilyEngine)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(IMGUI_BACKEND_SOURCES "src/backend/imgui_impl_opengl3.cpp" "src/backend/imgui_impl_sdl3.cpp")

set(IMGUI_BACKEND_HEADERS "src/backend/imgui_impl_opengl3.h","src/backend/imgui_impl_sdl3.h")

find_package(SDL3 REQUIRED)
find_package(imgui REQUIRED)
find_package(Lua REQUIRED)

add_library(LilyEngine "src/lua_exec.cpp" "src/sdl_render.cpp")

add_library(IMGUIBACKEND ${IMGUI_BACKEND_SOURCES})

target_include_directories(IMGUIBACKEND PUBLIC imgui::imgui)
target_link_libraries(IMGUIBACKEND PUBLIC imgui::imgui)

target_include_directories(LilyEngine PUBLIC imgui::imgui IMGUIBACKEND SDL3::SDL3  ${LUA_INCLUDE_DIR})
target_link_libraries(LilyEngine PUBLIC imgui::imgui IMGUIBACKEND SDL3::SDL3  ${LUA_LIBRARIES})

add_executable(Lily "src/main.cpp")

target_link_libraries(Lily PUBLIC LilyEngine)