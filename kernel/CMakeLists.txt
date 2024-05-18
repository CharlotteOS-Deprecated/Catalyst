cmake_minimum_required(VERSION 3.10)

set(PROJECT_N kernel)
project(${PROJECT_N} LANGUAGES C ASM VERSION 0.1.0)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

# Make sure we are using clang
if(NOT CMAKE_C_COMPILER_ID MATCHES "Clang")
	message(FATAL_ERROR "Only Clang is supported")
endif()

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/**/*.c)
file(GLOB_RECURSE ASSEMBLY_SRCS ${PROJECT_SOURCE_DIR}/**/*.asm)

# a macro that gets all of the header containing directories.
macro(header_directories return_list includes_base_folder extention)
	file(GLOB_RECURSE new_list ${includes_base_folder}/*.${extention})
	set(dir_list "")
	foreach(file_path ${new_list})
		get_filename_component(dir_path ${file_path} PATH)
		set(dir_list ${dir_list} ${dir_path})
	endforeach()
	list(REMOVE_DUPLICATES dir_list)
	set(${return_list} ${dir_list})
endmacro()
# a macro that gets all of the header containing directories.
header_directories(INCLUDES ${PROJECT_SOURCE_DIR}/**/ h)

# global cflags
set(CMAKE_C_COMPILE_FLAGS "${CMAKE_C_FLAGS} -std=c2x -Wall -Wextra -Werror -pedantic -std=c2x -ffreestanding -fno-stack-protector -fno-stack-check -fno-lto -fpic -mcmodel=kernel")

if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
	message(STATUS "x86_64 target detected")

	add_definitions(-DARCH_X86_64)

	# set cfags for x86_64
	set(CMAKE_C_COMPILE_FLAGS "${CMAKE_C_FLAGS} -target x86_64-elf -m64 -march=x86-64 -mno-80387 -mno-mmx -mno-sse -mno-sse2 -mno-red-zone")

	# set linker flags for x86_64
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${PROJECT_SOURCE_DIR}/linker-x86_64.ld")

	# Make sure we are using nasm
	if(NOT CMAKE_ASM_COMPILER_ID MATCHES "NASM")
		message(FATAL_ERROR "Only NASM is supported got ${CMAKE_ASM_COMPILER_ID}")
	endif()

	enable_language(ASM_NASM)
	set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
else()
	# Currently only x86_64 is supported
	message(FATAL_ERROR "Unsupported architecture")
endif()

add_executable(${PROJECT_N} ${SRCS} ${ASSEMBLY_SRCS})
set_target_properties(${PROJECT_N} PROPERTIES LINKER_LANGUAGE C)
target_include_directories(${PROJECT_N} PUBLIC ${PROJECT_SOURCE_DIR}/../limine)
target_include_directories(${PROJECT_N} PUBLIC ${PROJECT_SOURCE_DIR}/src)
