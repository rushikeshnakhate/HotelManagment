set(PROJECT_NAME HotelManagementMain)
project(${PROJECT_NAME})
file(GLOB SOURCES *cpp *h)
add_executable(${PROJECT_NAME} ${SOURCES})