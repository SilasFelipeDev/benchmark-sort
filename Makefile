CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = $(wildcard src/*.c)

OBJ = $(patsubst src/%.c,build/%.o,$(SRC))

TARGET = benchmark

ifeq ($(OS), Windows_NT)
	RM = del /Q
	EXE = .exe
else
	RM = rm -f
	EXE = 
endif

all: $(TARGET)$(EXE)

$(TARGET)$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) build\*.o
	$(RM) $(TARGET)$(EXE)