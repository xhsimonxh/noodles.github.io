cmake_minimum_required( VERSION 3.10.0)

project(QtreeViewModelTest)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package( Qt5Widgets REQUIRED )
file( GLOB ui_list *.ui )
file( GLOB header_list *.h )
file(GLOB cpp_list *.cpp)
qt5_wrap_ui( UI_HEADERS ui_list)
#qt5_add_resources(qrc_FILES registrationtest.qrc)

add_executable( ${PROJECT_NAME} ${header_list} ${cpp_list} ${ui_list})
#qt5_use_modules(QtreeViewModelTest Widgets)  
target_link_libraries( ${PROJECT_NAME} Qt5::Widgets)