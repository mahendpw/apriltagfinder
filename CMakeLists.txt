cmake_minimum_required(VERSION 2.6)
project(apriltags)
set(CMAKE_CXX_COMPILER /usr/bin/c++)
configure_file(${CMAKE_SOURCE_DIR}/cmake/FindEigen.cmake
  ${CMAKE_BINARY_DIR}/FindEigen.cmake @ONLY)

set(CMAKE_MODULE_PATH
    ${CMAKE_BINARY_DIR}
    ${CMAKE_MODULE_PATH}
   )

file(GLOB SOURCE_FILES "src/*.cc")
include_directories(AprilTags . )
add_library(apriltags SHARED ${SOURCE_FILES})
link_directories(/usr/local/lib )
#find_package(Eigen REQUIRED)
#include_directories(${Eigen_INCLUDE_DIR})

#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("${PROJECT_BINARY_DIR}" /usr/local/include /usr/include/eigen3)
target_link_libraries(apriltags ${OpenCV_LIBS}) #-pg) #-fopenmp)

#add_subdirectory(example)

# Add stuff for an install target.
file(GLOB HEADER_FILES ${CMAKE_SOURCE_DIR}/AprilTags/*)
install(PROGRAMS ${HEADER_FILES} DESTINATION include/AprilTags COMPONENT applications)
install(TARGETS apriltags
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib 
  ARCHIVE DESTINATION lib
  
  )
