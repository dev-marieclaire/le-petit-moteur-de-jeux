# SRC = ./src/main.c ./src/init.c ./src/screen.c
SRC = ./src/*.cpp ./src/*.c
INCLUDE = -I./include/
OUT = ./build/main
LFLAGS = `pkg-config --cflags --libs sdl2 SDL2_image`

all: compile exec

clean:
	rm -fr ./{build,src}/*.o

compile:
	g++ $(SRC) $(INCLUDE) -g -o $(OUT) $(LFLAGS)

exec:
	cd ./build && SDL_VIDEODRIVER=x11 ./main