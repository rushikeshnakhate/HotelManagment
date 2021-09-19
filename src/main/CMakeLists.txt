set(PROJECT_NAME HotelManagementMain)
project(${PROJECT_NAME})
file(GLOB SOURCES *cpp)
add_executable(${PROJECT_NAME} ${SOURCES})