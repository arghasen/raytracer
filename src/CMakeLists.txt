# Make an automatic library - will be static or dynamic based on user setting
add_library(raytracer vec3d.cpp)

# We need this directory, and users of our library will need it too
target_include_directories(raytracer PUBLIC ${PROJECT_SOURCE_DIR}/include)

# All users of this library will need at least C++17
target_compile_features(raytracer PUBLIC cxx_std_17)

add_executable(raytracer-bin main.cpp)
target_link_libraries(raytracer-bin PRIVATE raytracer)
set_target_properties(raytracer-bin PROPERTIES OUTPUT_NAME raytracer)

install(
    TARGETS raytracer
    RUNTIME DESTINATION bin)
