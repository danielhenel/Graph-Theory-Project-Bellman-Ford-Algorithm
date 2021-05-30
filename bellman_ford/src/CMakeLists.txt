add_executable (bellman_ford main.cpp graph.cpp  bellman_ford.cpp)

add_custom_target(run_bellman_ford DEPENDS bellman_ford 
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/bellman_ford
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/graphs DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_custom_target(valgrind_bellman_ford DEPENDS bellman_ford
     COMMAND
       valgrind --leak-check=full ${CMAKE_CURRENT_BINARY_DIR}/bellman_ford)