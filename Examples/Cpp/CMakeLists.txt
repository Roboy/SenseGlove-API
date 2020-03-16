cmake_minimum_required(VERSION 3.5)
project (TestLibrary)

#For the shared library:
# set ( PROJECT_LINK_LIBS SGCore.so )
set(CMAKE_SHARED_LIBRARY_PREFIX "")
find_library(SENSEGLOVE SGCore.so HINTS /home/missxa/workspace/senseglove_ws/src/SenseGlove-API/Core/SGCoreCpp/lib/Linux)

# link_directories( /home/missxa/workspace/senseglove_ws/src/SenseGlove-API/Core/SGCoreCpp/ )


include_directories(~/workspace/senseglove_ws/src/SenseGlove-API/Core/SGCoreCpp/incl)

add_executable(senseglove SGCoreCpp_Example.cpp)
target_link_libraries(senseglove ${SENSEGLOVE} )
