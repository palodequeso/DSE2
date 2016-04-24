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
    set(EXTLIBS sfml-graphics sfml-window sfml-system sfml-audio sfml-network glew32 tbb)
ELSE (WIN32)
    find_package(Protobuf REQUIRED)
    set(CMAKE_CXX_FLAGS_DEBUG "-g -pg -ggdb -Wall -std=c++11 -Wno-reorder")
    set(CMAKE_CXX_FLAGS_RELEASE "-Wall -std=c++11 -Wno-reorder")
    set(CMAKE_SHARED_LINKER_FLAGS "-pg -g")
    add_definitions(-pg -Wall -ggdb -std=c++11)
    include_directories(/usr/local/include/ /usr/local/include/bullet/ /usr/include/postgresql/9.4/server/ ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
    set(EXTLIBS sfml-graphics sfml-window sfml-system sfml-audio sfml-network GL
        GLEW glut GLU Xrandr awesomium-1-7 tbb boost_system boost_filesystem BulletDynamics BulletCollision
        LinearMath ${PROTOBUF_LIBRARY})
ENDIF (WIN32)

#add_subdirectory(common)
add_subdirectory(engine)
#add_subdirectory(server)
add_subdirectory(applications)
