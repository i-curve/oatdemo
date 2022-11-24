aux_source_directory(. TEST_SOURCE)

add_executable(test ${TEST_SOURCE})
target_link_libraries(test oatpp::oatpp-test)
