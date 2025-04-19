CC = g++
OBJECT_PATH = -I/path/to/raylib/include
LINKED_PATH = -L/path/to/raylib/lib
LINKED_FLAG = -lraylib -lm -lpthread -ldl -lrt -lX11
BUILD_DIR = ../bin/
NAME = tetris

all : object linked go

object : main.o play.o grid.o colors.o blocks.o block.o font.o

main.o : main.cpp main.hpp
	$(CC) -c main.cpp $(OBJECT_PATH) -o main.o

play.o : play.cpp play.hpp
	$(CC) -c play.cpp $(OBJECT_PATH) -o play.o

grid.o : grid.cpp grid.hpp
	$(CC) -c grid.cpp $(OBJECT_PATH) -o grid.o

colors.o : colors.cpp colors.hpp
	$(CC) -c  colors.cpp $(OBJECT_PATH) -o colors.o

blocks.o : blocks.cpp blocks.hpp
	$(CC) -c blocks.cpp $(OBJECT_PATH) -o blocks.o

block.o : block.cpp block.hpp
	$(CC) -c block.cpp $(OBJECT_PATH) -o block.o

font.o : font.cpp font.hpp
	$(CC) -c font.cpp $(OBJECT_PATH) -o font.o

linked : main.o play.o grid.o colors.o blocks.o block.o font.o
	$(CC) main.o play.o grid.o colors.o blocks.o block.o font.o -o $(BUILD_DIR)$(NAME) $(LINKED_PATH) $(LINKED_FLAG)

go :
	$(BUILD_DIR)$(NAME)

clean :
	rm -rf *.o
	rm -rf $(BUILD_DIR)*

rebuild : object linked

style_check :
	find . -name "*.cpp" -o -name "*.hpp" | xargs clang-format -n --style=Google

style :
	find . -name "*.cpp" -o -name "*.hpp" | xargs clang-format -i --style=Google