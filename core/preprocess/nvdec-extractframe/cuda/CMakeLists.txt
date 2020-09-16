project(hwgpu)
FIND_PACKAGE(CUDA ${CUDA_VERSION} REQUIRED)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp *.cuh)
file(GLOB CURRENT_SOURCES  *.cpp *.cu)
file(GLOB CUDA_LIBS /usr/local/cuda-10.0/lib64/*.so)

source_group("Include" FILES ${CURRENT_HEADERS})
source_group("Source" FILES ${CURRENT_SOURCES})

set(CMAKE_CUDA_FLAGS "-ccbin -Xcompiler -fPIC --std=c++11")
set(CUDA_NVCC_FLAGS "-Xcompiler -fPIC --std=c++11")

include_directories("/usr/local/cuda-10.0/include")
include_directories("./Util")

cuda_add_library(hwgpu SHARED ${CURRENT_HEADERS} ${CURRENT_SOURCES})
target_link_libraries(hwgpu ${CUDA_LIBS})
