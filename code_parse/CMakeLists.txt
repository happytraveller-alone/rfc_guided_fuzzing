cmake_minimum_required(VERSION 3.15)
project(Code_parse)

# Set the C++ standard to C++17 and the C standard to C17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

# Specify the C and C++ compilers only if on Windows
if(WIN32)
    set(CMAKE_C_COMPILER "D:/Program Files/LLVM/bin/clang.exe")
    set(CMAKE_CXX_COMPILER "D:/Program Files/LLVM/bin/clang++.exe")
endif()

# Include the ANTLR4 runtime library from your project directory
set(ANTLR4_ROOT ${CMAKE_SOURCE_DIR}/tool)
include_directories(${ANTLR4_ROOT}/src)

# Gather all source files
file(GLOB_RECURSE SOURCES "grammar/*.cpp" "grammar/*.h")

# Add the executable
add_executable(Code_parse
    Check.cpp
    ${SOURCES}
)

# Link against the ANTLR4 runtime library based on the platform
if(WIN32)
    target_link_libraries(Code_parse ${ANTLR4_ROOT}/lib/antlr4-runtime)
else()
    target_link_libraries(Code_parse ${ANTLR4_ROOT}/lib/libantlr4-runtime.a)
endif()

# Add compile flags
target_compile_options(Code_parse PRIVATE
    -Wall
    -Wextra
    -std=c++17
)

# Optionally, you can add platform-specific flags
if(WIN32)
    target_compile_options(Code_parse PRIVATE
        # Add Windows-specific flags here
    )
else()
    target_compile_options(Code_parse PRIVATE
        # Add Unix-specific flags here
    )
endif()