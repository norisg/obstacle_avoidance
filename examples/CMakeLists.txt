add_executable(recognize_object
                src/recognize_objects.cpp)
add_executable(video_recording
src/video_recording.cpp)
add_executable(gpio_rpi
  src/gpio_rpi.cpp)


TARGET_LINK_LIBRARIES (recognize_object ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES (video_recording ${OpenCV_LIBS})

FIND_PACKAGE(WiringPi REQUIRED)

# Include headers
include_directories(${WIRINGPI_INCLUDE_DIRS})

# Link against libraries
target_link_libraries(gpio_rpi ${WIRINGPI_LIBRARIES})
target_link_libraries(gpio_rpi ${CMAKE_THREAD_LIBS_INIT})

FILE(COPY Resources DESTINATION "${CMAKE_BINARY_DIR}")
