project (playground)

set(${PROJECT_NAME}_SOURCE playground.cpp)

# add subfolders
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})

# add dependencies
target_link_libraries (${PROJECT_NAME} ndutils)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
