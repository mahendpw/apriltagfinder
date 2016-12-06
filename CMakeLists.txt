cmake_minimum_required(VERSION 2.6)
project(apriltags)
set(CMAKE_CXX_COMPILER /usr/local/oecore-i686/sysroots/i686-angstromsdk-linux/usr/bin/arm-angstrom-linux-gnueabi/arm-angstrom-linux-gnueabi-g++)
configure_file(${CMAKE_SOURCE_DIR}/cmake/FindEigen.cmake
  ${CMAKE_BINARY_DIR}/FindEigen.cmake @ONLY)

set(CMAKE_MODULE_PATH
    ${CMAKE_BINARY_DIR}
    ${CMAKE_MODULE_PATH}
   )

file(GLOB SOURCE_FILES "src/*.cc")
include_directories(AprilTags . )
add_library(apriltags SHARED ${SOURCE_FILES})
link_directories(/usr/local/oecore-i686/sysroots/armv7ahf-vfp-neon-angstrom-linux-gnueabi/usr/lib /home/mv/matrix_vision/mvIMPACT_acquire-2.16.1/lib/armv7ahf )
#find_package(Eigen REQUIRED)
#include_directories(${Eigen_INCLUDE_DIR})

#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("${PROJECT_BINARY_DIR}" /usr/local/oecore-i686/sysroots/armv7ahf-vfp-neon-angstrom-linux-gnueabi/usr/include /home/mv/matrix_vision/mvIMPACT_acquire-2.16.1 /home/mv/matrix_vision/mvIMPACT_acquire-2.16.1 /usr/include/eigen3)
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
