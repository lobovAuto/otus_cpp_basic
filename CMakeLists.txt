cmake_minimum_required(VERSION 3.5)

project(01.hello_world)

set(TARGET_NAME hello_world)

add_executable(hello_world 
    main.cpp
    components/example/example.cpp
    components/move_me_out/move_me_out.cpp
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set(INCLUDES
    ./components/example
    ./components/move_me_out 
)

target_include_directories(${TARGET_NAME} PRIVATE ${INCLUDES}
)