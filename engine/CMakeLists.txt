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
	
	./src/resources/resource.cpp
	./include/resources/resource.h
	./src/resources/resource_manager.cpp
	./include/resources/resource_manager.h
)

IF (WIN32)
    link_directories(${DEPENDS_DIR}/lib)
    include_directories(${DEPENDS_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})
    add_library(dsengine STATIC ${SRCS})
    target_link_libraries(dsengine ${EXTLIBS})
ELSE (WIN32)
    include_directories(/usr/local/include/ /usr/local/)
    add_library(dsengine SHARED ${SRCS})
    target_link_libraries(dsengine dscommon)
ENDIF (WIN32)
