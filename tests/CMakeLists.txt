# Tests live as a subdirectory of the main project — no separate project() needed.
find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(tst_audioq tst_audioq.cpp)

target_link_libraries(tst_audioq PRIVATE Qt6::Test)

# Run with offscreen platform so tests work in headless CI
add_test(
    NAME    AudioQTests
    COMMAND tst_audioq
)
set_tests_properties(AudioQTests PROPERTIES
    ENVIRONMENT "QT_QPA_PLATFORM=offscreen"
)
