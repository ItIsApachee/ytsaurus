
# This file was generated by the build system used internally in Yandex and called "ya"
# (https://github.com/yandex/yatool).
#
# Configuration files of ya build system are usually named ya.make. If ya.make file is present
# at the root of the repository, then this repository supports ya build. 
# 
# If the repository supports both CMake and ya build configurations, please modify both of them.
#
# If only CMake build configuration is supported then modify only CMake files and note that only
# simple modifications are allowed like adding source-files to targets or adding simple properties
# like target_include_directories. These modifications will be ported to original ya.make files
# by maintainers. Any complex modifications which can't be easily ported back to the ya build 
# system may be rejected.

find_package(linux-headers-generic REQUIRED)
add_library(lib-MC-MCDisassembler)


target_compile_options(lib-MC-MCDisassembler PRIVATE
  $<IF:$<CXX_COMPILER_ID:MSVC>,,-Wno-everything>
)

target_include_directories(lib-MC-MCDisassembler PRIVATE
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler
)

target_link_libraries(lib-MC-MCDisassembler PUBLIC
  linux-headers-generic::linux-headers-generic
  contrib-libs-cxxsupp
  contrib-libs-llvm16
  llvm16-lib-MC
  llvm16-lib-Support
  llvm16-lib-TargetParser
)

target_sources(lib-MC-MCDisassembler PRIVATE
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler/Disassembler.cpp
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler/MCDisassembler.cpp
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler/MCExternalSymbolizer.cpp
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler/MCRelocationInfo.cpp
  ${PROJECT_SOURCE_DIR}/contrib/libs/llvm16/lib/MC/MCDisassembler/MCSymbolizer.cpp
)






