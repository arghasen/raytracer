add_executable(testrunner testrunner.cpp)
target_include_directories(testrunner PRIVATE 
            ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/extern
)
target_link_libraries(testrunner PRIVATE libraytracer)
target_compile_features(testrunner PRIVATE cxx_std_17)