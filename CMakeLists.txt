cmake_minimum_required (VERSION 3.2 FATAL_ERROR)
project (socketclient)

# Set Poco Install directories
if (UNIX)
  set(Poco_DIR "$ENV{HOME}/Projects/poco/cmake-build/Poco") 
  set(Poco_INCLUDE_DIRS "$ENV{HOME}/Projects/poco/")
endif (UNIX)
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)
# Lookup for necessary libraries in system
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Threads)
find_package(Poco REQUIRED COMPONENTS Foundation Net XML Util)
# Target server
add_executable(client src/client.cpp)
target_include_directories(client
    PUBLIC 
      inc
      ${CMAKE_BINARY_DIR}
      ${CMAKE_CURRENT_LIST_DIR}
    PRIVATE 
)
#target_compile_definitions(client
#    PRIVATE
#)
target_sources(client
        PRIVATE
	  src/client.cpp
          src/mainwindow.cpp
)
target_compile_options(client
    PUBLIC
    -D_DEBUG
    -fPIC
)
target_compile_features(client
    PUBLIC
	  cxx_auto_type
	  cxx_range_for
)
target_link_libraries(client 
    PUBLIC
	  Threads::Threads
	  Poco::Foundation
	  Poco::Util
	  Poco::Net
          Qt5::Widgets
          Qt5::Core
)
set_target_properties(client
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
