project(Lift)
cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 11)


ADD_LIBRARY(LibsModule
        n_distrubution.cpp
        )

target_link_libraries(LibsModule -lpthread)

#find_package(Curses)
#target_link_libraries(LibsModule -curses)
find_package( Curses REQUIRED )
include_directories( ${CURSES_INCLUDE_DIRS} )
target_link_libraries(LibsModule ${CURSES_LIBRARIES} )
ADD_EXECUTABLE(Lift main.cpp)

target_link_libraries(Lift LibsModule)

#find_package( PkgConfig REQUIRED )
#pkg_check_modules( ncurses++ REQUIRED ncurses++ )
#add_executable(Lift src/main.cpp)
#target_link_libraries( ${catkin_LIBRARIES} ncurses)
#add_dependencies(Lift ${catkin_EXPORTED_TARGETS} Liftcpp)
#add_executable(Lift   misc.h)