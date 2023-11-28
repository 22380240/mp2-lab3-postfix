file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_executable(postfix ${srcs} ${hdrs})

target_link_libraries(postfix lib)
