add_executable(recognize_object
                src/recognize_objects.cpp)
add_executable(video_recording
src/video_recording.cpp)
add_executable(gpio_rpi
  src/gpio_rpi.cpp)


TARGET_LINK_LIBRARIES (recognize_object ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES (video_recording ${OpenCV_LIBS})



target_link_libraries(gpio_rpi wiringPi pthread)


FILE(COPY Resources DESTINATION "${CMAKE_BINARY_DIR}")
