cmake_minimum_required(VERSION 3.23)
project(sakura)

set(CXX_STANDARD 23)

add_executable(sakura src/main.cpp lib/webgpu/webgpu.cpp src/core/application.cpp src/core/application.h src/core/layer.h src/sandbox/sandbox.cpp src/sandbox/sandbox.h src/core/window.cpp src/core/window.h src/gfx/wgpu_context.cpp src/gfx/wgpu_context.h src/core/base.h src/gfx/main_renderer.cpp src/gfx/main_renderer.h)

set_target_properties(sakura PROPERTIES CXX_STANDARD 23 COMPILE_WARNING_AS_ERROR ON)

add_subdirectory(lib)
target_link_libraries(sakura lib)

include_directories(src)
include_directories(lib)

target_copy_webgpu_binaries(sakura)
