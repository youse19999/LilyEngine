cmake_minimum_required(VERSION 3.20)

project(somnambulism)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(IMGUI_BACKEND_SOURCES "src/backend/imgui_impl_opengl3.cpp" "src/backend/imgui_impl_sdl3.cpp")

set(IMGUI_BACKEND_HEADERS "src/backend/imgui_impl_opengl3.h","src/backend/imgui_impl_sdl3.h")

find_package(SDL3 REQUIRED)
find_package(imgui REQUIRED)
find_package(Python3 COMPONENTS Development REQUIRED)
find_package(Lua REQUIRED)

add_library(somnambulism "src/renderer.cpp" "src/renderer.h" "src/main.cpp" "src/main.h" "src/lua.cpp" "src/lua.h")

add_library(IMGUIBACKEND ${IMGUI_BACKEND_SOURCES} "src/main.h" "src/lua.cpp" "src/lua.h")

add_executable(somnambulism_exec "src/main.cpp" "src/lua.cpp" "src/lua.h")

target_include_directories(IMGUIBACKEND PUBLIC imgui::imgui)
target_link_libraries(IMGUIBACKEND PUBLIC imgui::imgui)

target_include_directories(somnambulism PUBLIC imgui::imgui)
target_link_libraries(somnambulism PUBLIC imgui::imgui)

target_include_directories(somnambulism PUBLIC IMGUIBACKEND)
target_link_libraries(somnambulism PUBLIC IMGUIBACKEND)

target_include_directories(somnambulism PUBLIC SDL3::SDL3)
target_link_libraries(somnambulism PUBLIC SDL3::SDL3)

target_include_directories(somnambulism PUBLIC ${LUA_INCLUDE_DIR})
target_link_libraries(somnambulism PRIVATE ${LUA_LIBRARIES})

target_include_directories(somnambulism PUBLIC Python3::Python)
target_link_libraries(somnambulism PUBLIC Python3::Python)


target_include_directories(somnambulism_exec PUBLIC somnambulism)
target_link_libraries(somnambulism_exec PUBLIC somnambulism)
