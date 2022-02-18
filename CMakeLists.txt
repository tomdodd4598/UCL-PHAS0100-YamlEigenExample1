cmake_minimum_required(VERSION 3.5)

project(MyProject)

set(BinDir ${CMAKE_BINARY_DIR}/bin)
set(LibDir ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${LibDir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BinDir})

### ===== yaml-cpp (apt installed, 0.6.2) ===== ###

#find_package(yaml-cpp REQUIRED)

#add_executable(UseYaml useyaml.cpp)
#target_link_libraries(UseYaml PRIVATE yaml-cpp)

### ===== yaml-cpp (local build, 0.7.0) ===== ###

add_library(YamlCpp SHARED IMPORTED)
set_target_properties(YamlCpp PROPERTIES IMPORTED_LOCATION ${MyProject_SOURCE_DIR}/yaml-cpp/build/libyaml-cpp.so)

add_executable(UseYaml useyaml.cpp)
target_link_libraries(UseYaml PRIVATE YamlCpp)
target_include_directories(UseYaml PRIVATE ${MyProject_SOURCE_DIR}/yaml-cpp/include)

### ===== eigen ===== ###

add_executable(EigenExample eigenexample.cpp)
target_include_directories(EigenExample PRIVATE ${MyProject_SOURCE_DIR}/eigen)

### ===== nlohmann json ===== ###

add_executable(JsonTest jsontest.cpp)
target_include_directories(JsonTest PRIVATE ${MyProject_SOURCE_DIR}/json/single_include/nlohmann)
