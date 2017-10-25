cmake_minimum_required( VERSION 3.1 )

set( app basic_db )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

include_directories( ${CMAKE_CURRENT_LIST_DIR}/../../include )
link_directories( ${CMAKE_CURRENT_LIST_DIR}/../../out-static )
find_package( Threads )

set( src main.cc )
add_executable( ${app} ${src} )
target_link_libraries( ${app} leveldb ${CMAKE_THREAD_LIBS_INIT} )
