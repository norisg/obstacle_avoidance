add_executable(recognize_object
                src/recognize_objects.cpp)


TARGET_LINK_LIBRARIES (recognize_object ${OpenCV_LIBS})


FILE(COPY Resources DESTINATION "${CMAKE_BINARY_DIR}")
