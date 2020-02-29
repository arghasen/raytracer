# Make an automatic library - will be static or dynamic based on user setting
add_library(libraytracer vec3d.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(libraytracer PUBLIC ${PROJECT_SOURCE_DIR}/include)

# All users of this library will need at least C++17
target_compile_features(libraytracer PUBLIC cxx_std_17)

add_executable(raytracer main.cpp)
target_link_libraries(raytracer PRIVATE libraytracer)

install(
    TARGETS raytracer
    RUNTIME DESTINATION bin)
