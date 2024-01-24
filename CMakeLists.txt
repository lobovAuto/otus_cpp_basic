cmake_minimum_required(VERSION 3.5)

project(02.guess_number)

set(TARGET_NAME guess_number)

add_executable( ${TARGET_NAME}
    main/main.cpp
    components/game/game.cpp
    components/result/result.cpp
    components/players_name/players_name.cpp
)

set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set(INCLUDES
    ./components/game
    ./components/result
    ./components/players_name 
)

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDES}
)