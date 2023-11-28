file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(test_all ${srcs} ${hdrs})

target_link_libraries(test_all gtest lib)
