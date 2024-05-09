cmake_minimum_required(VERSION 3.10)
project(testing_embed_python VERSION 0.1.0 LANGUAGES C CXX)

# Locate Python installation
set(PYTHON_INCLUDE_DIR "/usr/include/python3.12/")
set(PYTHON_LIBRARY_DIR "/usr/lib64/python3.12/")
set(LIBPYTHON_PATH "/usr/lib64/libpython3.12.so")

# Find all your source files
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Create your executable
add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

# Set C++ standard
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 17)

target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/") # This is useful to get an ASSETS_PATH in your IDE during development but you should comment this if you compile a release version and uncomment the next line
#target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/") # Uncomment this line to setup the ASSETS_PATH macro to the final assets directory when you share the game


# Include directories for your project
target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
    "${PYTHON_INCLUDE_DIR}"
)

# Link against the Python library
target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    "${LIBPYTHON_PATH}"
)