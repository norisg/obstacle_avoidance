add_executable(recognize_object
                src/recognize_objects.cpp)
add_executable(video_recording
src/video_recording.cpp)


TARGET_LINK_LIBRARIES (recognize_object ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES (video_recording ${OpenCV_LIBS})



FILE(COPY Resources DESTINATION "${CMAKE_BINARY_DIR}")
