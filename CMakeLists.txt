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


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
file(GLOB_RECURSE TEST_LIST CONFIGURE_DEPENDS "test/*.cc")
add_executable(kamige--googletest ${TEST_LIST})
target_link_libraries(kamige--googletest gtest_main)
target_include_directories(kamige--googletest PUBLIC "./src")
add_test(NAME test COMMAND kamige--googletest)
enable_testing()


if(MSVC)
    message("This compiller is MSVC.")
    target_compile_options(kamige- PRIVATE /W4 /WX)
else()
    message(FATAL_ERROR "Compilers other than MSVC are not supported.")
endif()
