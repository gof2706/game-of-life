CFLAGS = -Wall -Werror
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJ = g++ -std=c++11 $(CFLAGS) -c $< -o $@ $(SFML) 
TEST = g++ -std=c++11 $(GFAGS) -I thirtdparty/catch2 -c $< -o $@

.PHONY: clean

all: target1 target2 target3 bin/game_of_life.exe 

target1:
	mkdir -p build/src

target2:
	mkdir -p bin

target3:
	mkdir -p build/test

bin/game_of_life.exe: build/src/main.o build/src/outp.o build/src/fillrand.o build/src/logic.o build/src/fillbill.o build/src/fillpuls.o build/src/filldroz.o build/src/fillpalk.o build/src/fillskre.o build/src/fillprac.o build/src/filltumb.o

	g++ -std=c++11 $(CFLAGS) $^ -o $@ $(SFML)

build/src/main.o: src/main.cpp src/game.h
	$(OBJ)

build/src/logic.o: src/logic.cpp src/game.h
	$(OBJ)

build/src/outp.o: src/outp.cpp src/game.h
	$(OBJ)

build/src/fillrand.o: src/fillrand.cpp src/game.h
	$(OBJ)

build/src/fillbill.o: src/fillbill.cpp src/game.h
	$(OBJ)

build/src/fillpuls.o: src/fillpuls.cpp src/game.h
	$(OBJ)

build/src/filldroz.o: src/filldroz.cpp src/game.h
	$(OBJ)

build/src/fillpalk.o: src/fillpalk.cpp src/game.h
	$(OBJ)

build/src/fillskre.o: src/fillskre.cpp src/game.h
	$(OBJ)

build/src/fillprac.o: src/fillprac.cpp src/game.h
	$(OBJ)

build/src/filltumb.o: src/filltumb.cpp src/game.h
	$(OBJ)

bin/goltest.exe: build/test/logic.o build/test/test.o
	g++ $(CFLAGS) -I thirtdparty/catch2  $^ -o $@

build/test/logic.o: test/logic.cpp test/game.h
	$(TEST)

build/test/test.o: test/test.cpp test/game.h
	$(TEST)

clean:
	rm build/*.o
	rm bin/*.exe
	rm -R build
	rm -R bin
