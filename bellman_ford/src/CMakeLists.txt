add_executable (bellman_ford main.cpp graph.cpp)

add_custom_target(run_bellman_ford DEPENDS bellman_ford
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/bellman_ford
)