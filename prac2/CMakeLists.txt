cmake_minimum_required(VERSION 3.1)
project(prac2)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set (CMAKE_CXX_STANDARD 11)
find_package(OpenCV REQUIRED)

include_directories(${OPENCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

link_directories(${OpenCV_LIBRARY_DIRS})

add_executable(generate_marker src/generate_marker.cpp)
target_sources(generate_marker PRIVATE src/dictionary.cpp)
target_link_libraries(generate_marker ${OpenCV_LIBRARIES})

add_executable(generate_board src/generate_board.cpp)
target_sources(generate_board PRIVATE src/dictionary.cpp)
target_link_libraries(generate_board ${OpenCV_LIBRARIES})

add_executable(detect_markers src/detect_markers.cpp)
target_sources(detect_markers PRIVATE src/dictionary.cpp)
target_link_libraries(detect_markers ${OpenCV_LIBRARIES})

add_executable(calibrate_camera src/calibrate_camera.cpp)
target_link_libraries(calibrate_camera ${OpenCV_LIBRARIES})

add_executable(pose_estimation src/pose_estimation.cpp)
target_link_libraries(pose_estimation ${OpenCV_LIBRARIES})

add_executable(draw_cube src/draw_cube.cpp)
target_link_libraries(draw_cube ${OpenCV_LIBRARIES})
