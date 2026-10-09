.PHONY: build run all

default:
	ninja -C build

all:
	cmake -B build -G "Ninja"
	make build
