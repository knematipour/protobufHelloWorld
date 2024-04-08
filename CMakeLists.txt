cmake_minimum_required(VERSION 3.22)

project(helloWorld C CXX)

option(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)

if(CMAKE_CROSSCOMPILING)
    find_program(_PROTOBUF_PROTOC protoc)
else()
    set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()

include_directories(${PROTOBUF_INCLUDE_DIR})

include_directories(proto)

add_executable(helloWorld main.cpp build/proto/helloworld.pb.cc)
target_link_libraries(helloWorld
    ${_PROTOBUF_LIBPROTOBUF}
)