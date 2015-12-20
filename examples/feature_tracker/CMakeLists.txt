project (feature_tracker)

set(${PROJECT_NAME}_SOURCE main.cpp feature_tracker_application.cpp)

# add subfolders
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})