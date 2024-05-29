.PHONY: *

create-debug:
	@cd ./cmake-build-debug && cmake ..

build-debug:
	@cd ./cmake-build-debug && make
	@# Or cd ./cmake-build-debug && cmake --build .

run-debug:
	@./cmake-build-debug/cmake_demo