cmake_minimum_required(VERSION 3.5)
project(myosc)

set(CMAKE_CXX_STANDARD 17)

add_executable(ch3_exercise_3.19 ch3/exercise/3.19.cpp)
add_executable(ch3_exercise_3.19_v2 ch3/exercise/3.19_v2.cpp)
add_executable(ch3_book_share_mem ch3/book/share_mory_between_threads.c)
add_executable(ch3_book_pipe_example ch3/book/pipe_example.c)

target_link_libraries(ch3_exercise_3.19 rt)