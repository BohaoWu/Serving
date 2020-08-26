cmake_minimum_required(VERSION 3.2)
project(hw-frame-extract)
SET(CUDA_VERSION 10.0)
FIND_PACKAGE(CUDA ${CUDA_VERSION} REQUIRED)
SET(CUDA_TARGET_INCLUDE ${CUDA_TOOLKIT_ROOT_DIR}-${CUDA_VERSION}/targets/${CMAKE_HOST_SYSTEM_PROCESSOR}-${LOWER_SYSTEM_NAME}/include)
include_directories(${CUDA_INCLUDE_DIRS})

execute_process(COMMAND nvcc --version)
execute_process(COMMAND gcc -v)
execute_process(COMMAND wget https://paddle-serving.bj.bcebos.com/external_code/preprocesslib.zip)
execute_process(COMMAND mv preprocesslib.zip ../core/preprocess/)
execute_process(COMMAND unzip -o ../core/preprocess/preprocesslib.zip -d ../core/preprocess/)

#gcc version
#GCC('gcc482')
#CUDA("10.1")

#Preprocessor flags.
file(GLOB DIR_LIBS ./lib/*.so)
file(GLOB DIR_FF_LIBS ./lib/*.so)

#C flags.
set(global_cflags_str "-g -pipe -W -Wall -fPIC -Wmissing-field-initializers")
set(CMAKE_C_FLAGS ${global_cflags_str})

#C++ flags.
set(global_cxxflags_str "-g -pipe -W -Wall -fPIC --std=c++11 -Wmissing-field-initializers")
set(CMAKE_CXX_FLAGS ${global_cxxflags_str})

#Preprocessor libs.
file(GLOB DIR_LIBS ./lib/*.so)
file(GLOB DIR_FF_LIBS ./lib/*.so)

#-I path
include_directories(.)
include_directories(./codessdkinclude/include)
include_directories(./ffmpeginclude/include)
include_directories(./include)
include_directories(./pybind11/include)
include_directories(./pythoninclude/python2.7/)
include_directories(/opt/compiler/cuda-10.1/include)
include_directories(./Utils)

#link flags
SET(GCC_COVERAGE_LINK_FLAGS '-lpthread -lrt')

#release headers
include_directories(*.h)
include_directories(*.hpp)
include_directories(include/*.h)
include_directories(include/*.hpp)

#bin
#Notice:
add_library(hw-frame-extract src/ExtractFrameBase.cpp
src/ExtractFrameJpeg.cpp src/ExtractFrameBGRARaw.cpp src/main.cpp
NvDecoder/NvDecoder.cpp Utils/ColorSpace.cu)
target_link_libraries(hw-frame-extract ${DIR_LIBS})

#.so
add_library(hwextract SHARED src/ExtractFrameBase.cpp src/ExtractFrameBGRARaw.cpp
src/ExtractFrameJpeg.cpp NvDecoder/NvDecoder.cpp pybind/pybind_frame_extract.cpp Utils/ColorSpace.cu)

add_library(hwextractcpp SHARED src/ExtractFrameBase.cpp src/ExtractFrameJpeg.cpp
src/ExtractFrameBGRARaw.cpp NvDecoder/NvDecoder.cpp Utils/ColorSpace.cu)

execute_process(COMMAND rm ../core/preprocess/preprocesslib.zip)
