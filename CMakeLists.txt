cmake_minimum_required(VERSION 3.20)

project(LilyEngine)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(IMGUI_BACKEND_SOURCES "src/backend/imgui_impl_opengl3.cpp" "src/backend/imgui_impl_sdl3.cpp")

set(IMGUI_BACKEND_HEADERS "src/backend/imgui_impl_opengl3.h","src/backend/imgui_impl_sdl3.h")

find_package(SDL3 REQUIRED)
find_package(imgui REQUIRED)
find_package(Python3 COMPONENTS Development REQUIRED)
find_package(Lua REQUIRED)

add_library(LilyEngine "src/renderer.cpp" "src/renderer.h" "src/main.cpp" "src/main.h" "src/lua.cpp" "src/lua.h")

add_library(IMGUIBACKEND ${IMGUI_BACKEND_SOURCES} "src/main.h" "src/lua.cpp" "src/lua.h")

add_executable(Lily "src/main.cpp" "src/lua.cpp" "src/lua.h")

target_include_directories(IMGUIBACKEND PUBLIC imgui::imgui)
target_link_libraries(IMGUIBACKEND PUBLIC imgui::imgui)

target_include_directories(LilyEngine PUBLIC imgui::imgui)
target_link_libraries(LilyEngine PUBLIC imgui::imgui)

target_include_directories(LilyEngine PUBLIC IMGUIBACKEND)
target_link_libraries(LilyEngine PUBLIC IMGUIBACKEND)

target_include_directories(LilyEngine PUBLIC SDL3::SDL3)
target_link_libraries(LilyEngine PUBLIC SDL3::SDL3)

target_include_directories(LilyEngine PUBLIC ${LUA_INCLUDE_DIR})
target_link_libraries(LilyEngine PRIVATE ${LUA_LIBRARIES})

target_include_directories(LilyEngine PUBLIC Python3::Python)
target_link_libraries(LilyEngine PUBLIC Python3::Python)


target_include_directories(Lily PUBLIC LilyEngine)
target_link_libraries(Lily PUBLIC LilyEngine)
