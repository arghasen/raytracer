set(TEST_SOURCES 
    #vec3d_test.cpp
    ray_test.cpp
    #shape_test.cpp
    shape_list_test.cpp
    matrix_impl_test.cpp
    color_test.cpp
    canvas_test.cpp
    translation_test.cpp
)

enable_testing()
include(GoogleTest)

add_executable(testrunner testrunner.cpp ${TEST_SOURCES})
target_include_directories(testrunner PRIVATE 
            ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/extern
)
target_link_libraries(testrunner PRIVATE raytracer gtest)
target_compile_features(testrunner PRIVATE cxx_std_17)

gtest_discover_tests(testrunner)
