# KeyBindings-Lightsout

CC = g++
SRC = main.cpp lightsout.cpp print.cpp
OBJ = $(SRC:.cpp=.o)
CFLAG = -Wall -Wextra -O3
LIB = -lncurses
EXE = keybindings-lightsout

.PHONY: all
all: $(EXE)

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXE)

.PHONY: rebuld
rebuild: clean all

$(EXE): $(OBJ)
	$(CC) $(CFLAG) -o $(EXE) $(OBJ) $(LIB)

.cpp.o:
	$(CC) $(CFLAG) -c $<
