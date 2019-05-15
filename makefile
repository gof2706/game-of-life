CFLAGS = -Wall -Werror
OBJ = g++ $(CFAGS) -c $< -o $@

.PHONY: clean

all: target1 target2 bin/game_of_life.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

bin/game_of_life.exe: build/main.o build/outp.o build/fillrand.o build/logic.o
	g++ $(CFLAGS) $^ -o $@

build/main.o: src/main.cpp src/game.h
	$(OBJ)

build/logic.o: src/logic.cpp src/game.h
	$(OBJ)

build/outp.o: src/outp.cpp src/game.h
	$(OBJ)

build/fillrand.o: src/fillrand.cpp src/game.h
	$(OBJ)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin
