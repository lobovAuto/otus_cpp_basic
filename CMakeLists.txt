cmake_minimum_required(VERSION 3.5)

project(02.guess_number)

set(TARGET_NAME guess_number)

add_executable( ${TARGET_NAME}
    main/main.cpp
    components/game_control/game_control.cpp
    components/result/result.cpp
    components/players_name/players_name.cpp
    components/args/args.cpp
    components/game/game.cpp
)

set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set(COMP_FLAGS -W -Wconversion)

set(INCLUDES
    ./components/game
    ./components/result
    ./components/players_name 
    ./components/game_control
    ./components/args
    ./components/help
)

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDES}
)

target_compile_options (${TARGET_NAME} PRIVATE ${COMP_FLAGS}
)

add_custom_target(copyBaseRes
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/result ${CMAKE_BINARY_DIR}/result
)

add_dependencies(${TARGET_NAME} copyBaseRes)