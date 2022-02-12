cmake_minimum_required(VERSION 3.5)

project(MyProject)

set(BinDir ${CMAKE_BINARY_DIR}/bin)
set(LibDir ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BinDir})

### ===== apt installed (0.6.2) ===== ###

#find_package(yaml-cpp REQUIRED)

#add_executable(UseYaml useyaml.cpp)
#target_link_libraries(UseYaml PRIVATE yaml-cpp)

### ===== local build (0.7.0) ===== ###

add_library(YamlCpp SHARED IMPORTED GLOBAL)
set_target_properties(YamlCpp PROPERTIES IMPORTED_LOCATION ${MyProject_SOURCE_DIR}/yaml-cpp/build/libyaml-cpp.so)

add_executable(UseYaml useyaml.cpp)
target_link_libraries(UseYaml PRIVATE YamlCpp)
target_include_directories(UseYaml PRIVATE ${MyProject_SOURCE_DIR}/yaml-cpp/include)

### ===== eigen ===== ###

#find_package(Eigen3 3.3 REQUIRED NO_MODULE)

#add_executable(EigenExample eigenexample.cpp)
#target_link_libraries(EigenExample Eigen3::Eigen)
