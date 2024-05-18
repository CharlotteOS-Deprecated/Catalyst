#!/usr/bin/env bash
# -*- coding: utf-8 -*-


function setup_cmake() {

	# if the kernel folder is not in the current working directory we stop everything
	if [ ! -d "kernel" ]; then
		echo "The kernel folder is not in the current working directory."
		echo "Please make sure to have the kernel folder in the current working directory."
		exit 1
	fi

	# delete the build folder if it exists
	if [ -d "build" ]; then
		rm -rf build
	fi

	# make sure limine.h is present in the limine folder
	if [ ! -f "limine/limine.h" ]; then
		echo "The limine.h file is not present in the vendor folder."
		echo "Please make sure to init the submodule."
		exit 1
	fi

	# Run cmake configuration
	cmake -S kernel -B build -DCMAKE_C_COMPILER=clang -DCMAKE_ASM_COMPILER=nasm -GNinja
}

# if called as meta.sh clean we delete the build folder
if [ "$1" = "clean" ]; then
	if [ -d "build" ]; then
		rm -rf build
	fi
	exit 0
elif [ "$1" = "configure" ]; then
	# check if clang is installed
	if ! command -v clang &> /dev/null; then
		echo "clang is not installed."
		echo "Please install clang before running the setup."
		exit 1
	fi
	setup_cmake
	exit 0
elif [ "$1" = "build" ]; then
	exit "$(ninja -C build)"
else
	echo "Usage: $0 [clean|configure|build]"
	exit 1
fi
