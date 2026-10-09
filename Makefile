build:
	ninja -C build
	make run

run:
	import .env
	./

all:
	cmake -B build -G "Ninja"
	make build
