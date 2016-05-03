cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../)

set(SRCS
    # core
    ./src/core/application.cpp
    ./include/core/application.h
    ./src/core/system.cpp
    ./include/core/system.h
    ./src/core/component.cpp
    ./include/core/component.h
    ./src/core/scheduler.cpp
    ./include/core/scheduler.h
    ./src/core/events.cpp
    ./include/core/events.h
    ./src/core/task.cpp
    ./include/core/task.h
    
    #game
    ./src/game/game.cpp
    ./include/game/game.h
    ./src/game/entity.cpp
    ./include/game/entity.h
    ./src/game/scene.cpp
    ./include/game/scene.h

    #resources
    ./src/resources/resource.cpp
    ./include/resources/resource.h
    ./src/resources/resource_manager.cpp
    ./include/resources/resource_manager.h

	#graphics
	./src/graphics/renderer.cpp
	./include/graphics/renderer.h
)

IF (WIN32)
    link_directories(${DEPENDS_DIR}/lib)
    include_directories(${DEPENDS_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})
    add_library(dsengine STATIC ${SRCS})
    target_link_libraries(dsengine ${EXTLIBS})
ELSE (WIN32)
    include_directories(/usr/local/include/ /usr/local/)
    add_library(dsengine SHARED ${SRCS})
    target_link_libraries(dsengine)
ENDIF (WIN32)
