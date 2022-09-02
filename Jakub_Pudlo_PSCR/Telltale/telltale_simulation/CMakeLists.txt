add_executable(telltale_simulation telltale_simulation.c
                              keyboard.c
                              logger.c
                              periodic.c
                              simulation.c
                              screen.c
                              node1.c
                              node2.c)

target_link_libraries(telltale_simulation pthread rt)