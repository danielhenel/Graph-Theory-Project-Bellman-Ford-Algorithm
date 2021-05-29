add_executable (bellman_ford main.cpp graph.cpp adjacency_list_1.txt bellman_ford.cpp bellman_ford.h)

add_custom_target(run_bellman_ford DEPENDS bellman_ford 
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/bellman_ford
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/adjacency_list_1.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/incident_matrix_1.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)