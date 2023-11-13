project(UnitTests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(UnitTests ScopeInterpreterTest.cpp AbstractSyntaxTreeBuilderTest.cpp LiteralParserTest.cpp ApplicationTest.cpp)

target_link_libraries(UnitTests t7tp1_src)
target_link_libraries(UnitTests gtest gtest_main)