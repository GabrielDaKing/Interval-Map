cmake_minimum_required(VERSION 3.9)
project(IntervalMap VERSION 0.1 DESCRIPTION "Simple implementaion of Interval Maps")

include(GNUInstallDirs)
include_directories(include/interval_map)
add_library(${PROJECT_NAME} SHARED src/interval_map.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER include/interval_map/interval_map.hpp)
configure_file(interval_map.pc.in interval_map.pc @ONLY)
target_include_directories(${PROJECT_NAME} PRIVATE .)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/interval_map.pc
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)