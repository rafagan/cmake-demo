.PHONY: *

run: build-debug run-debug

build-debug:
	@cd ./cmake-build-debug && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
	@cd ./cmake-build-debug && make

build-release:
	@cd ./cmake-build-release && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
	@cd ./cmake-build-release && make

run-debug:
	@./cmake-build-debug/cmake_demo

run-release:
	@./cmake-build-release/cmake_demo

install-boost:
	brew install boost
	@# sudo apt install libboost-all-dev