cmake_minimum_required(VERSION 3.24.1)
project(kamige- LANGUAGES CXX VERSION 1.0)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "src/*.cc")
add_executable(kamige- ${SOURCE_LIST})
target_include_directories(kamige- PRIVATE third_party/SDL2-2.24.0/include PRIVATE third_party/SDL2_image-2.6.2/include)
target_link_directories(kamige- PRIVATE third_party/SDL2-2.24.0/lib/x64 PRIVATE third_party/SDL2_image-2.6.2/lib/x64)
target_link_libraries(kamige- SDL2 SDL2main SDL2_image)


if(MSVC)
    message("This compiller is MSVC.")
    target_compile_options(kamige- PRIVATE /W4 /WX)
else()
    message(FATAL_ERROR "Compilers other than MSVC are not supported.")
endif()
