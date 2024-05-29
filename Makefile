.PHONY: *

create-debug:
	# "Ninja"
	@cd ./cmake-build-debug && cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..

create-release:
	@cd ./cmake-build-release && cmake -DCMAKE_BUILD_TYPE=Release ..

build-debug:
	@cd ./cmake-build-debug && make
	@# Or cd ./cmake-build-debug && cmake --build .

run-debug:
	@./cmake-build-debug/cmake_demo

run-release:
	@./cmake-build-release/cmake_demo