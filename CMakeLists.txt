cmake_minimum_required(VERSION 2.6)
project(DeepSpaceGames)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DeepSpaceGames_SOURCE_DIR}/build")

IF (WIN32)
    set(CMAKE_CXX_FLAGS_DEBUG "/W0")
    set(CMAKE_CXX_FLAGS_RELEASE "/W0")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
    SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")
    set(DEPENDS_DIR ${DeepSpaceGames_SOURCE_DIR}/dependencies/)
    set(CMAKE_LIBRARY_PATH ${DEPENDS_DIR}/lib)
    set(CMAKE_INCLUDE_PATH ${DEPENDS_DIR}/include)
    #find_package(Protobuf REQUIRED)
    include_directories(
        #${DEPENDS_DIR}/include/cpptest
        #${DEPENDS_DIR}/include/postgres
        #${DEPENDS_DIR}/include/postgres/server
        #${DEPENDS_DIR}/include/postgres/server/port/win32
        ${DEPENDS_DIR}/include
        ${DeepSpaceGames_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR})
    link_directories(${DEPENDS_DIR}/lib)
    set(EXTLIBS sfml-graphics sfml-window sfml-system sfml-audio sfml-network vulkan)
ELSE (WIN32)
    #find_package(Protobuf REQUIRED)
    set(CMAKE_CXX_FLAGS_DEBUG "-g -pg -ggdb -Wall -std=c++11 -pthread -Wno-reorder")
    set(CMAKE_CXX_FLAGS_RELEASE "-Wall -std=c++11 -Wno-reorder -pthread")
    set(CMAKE_SHARED_LINKER_FLAGS "-pg -g -pthread")
    set(DEPENDS_DIR ${DeepSpaceGames_SOURCE_DIR}/dependencies/)
    include_directories(
        ${DEPENDS_DIR}/include
        ${DeepSpaceGames_SOURCE_DIR}
        ${CMAKE_CURRENT_BINARY_DIR})
    add_definitions(-pg -Wall -ggdb -std=c++11)
    set(EXTLIBS sfml-graphics sfml-window sfml-system sfml-audio sfml-network vulkan)
ENDIF (WIN32)

#add_subdirectory(common)
add_subdirectory(engine)
#add_subdirectory(server)
add_subdirectory(applications)
