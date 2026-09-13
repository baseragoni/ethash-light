add_executable(ethash-light_tests test_core.cpp)
target_link_libraries(ethash-light_tests PRIVATE work)
target_include_directories(ethash-light_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
add_test(NAME core COMMAND ethash-light_tests)
