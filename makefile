CFLAGS = -Wall
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = g++ $(CFLAGS) -c $< -o $@ $(SFML) 

.PHONY: clean

all: target1 target2 bin/game_of_life.exe

target1:
	mkdir -p build

target2:
	mkdir -p bin

bin/game_of_life.exe: build/main.o build/outp.o build/fillrand.o build/logic.o build/fillbill.o build/fillpuls.o build/filldroz.o build/fillpalk.o build/fillskre.o build/fillprac.o build/filltumb.o

	g++ $(CFLAGS) $^ -o $@ $(SFML)

build/main.o: src/main.cpp src/game.h
	$(OBJ)

build/logic.o: src/logic.cpp src/game.h
	$(OBJ)

build/outp.o: src/outp.cpp src/game.h
	$(OBJ)

build/fillrand.o: src/fillrand.cpp src/game.h
	$(OBJ)

build/fillbill.o: src/fillbill.cpp src/game.h
	$(OBJ)

build/fillpuls.o: src/fillpuls.cpp src/game.h
	$(OBJ)

build/filldroz.o: src/filldroz.cpp src/game.h
	$(OBJ)

build/fillpalk.o: src/fillpalk.cpp src/game.h
	$(OBJ)

build/fillskre.o: src/fillskre.cpp src/game.h
	$(OBJ)

build/fillprac.o: src/fillprac.cpp src/game.h
	$(OBJ)

build/filltumb.o: src/filltumb.cpp src/game.h
	$(OBJ)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin
