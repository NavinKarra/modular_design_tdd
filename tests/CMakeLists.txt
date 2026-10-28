include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.2
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(greeter_tests greeter_test.cpp)
target_include_directories(greeter_tests PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(greeter_tests PRIVATE  GTest::gmock_main)
gtest_discover_tests(greeter_tests)
