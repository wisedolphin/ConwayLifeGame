CC=g++
CFLAGS= -c -Wall
SOURCES=main.cpp World_field.cpp
OBJ=$(SOURCES:.cpp=.o)
DEPS=World_field.h Cell.h
EXE=Conway_game


all: $(SOURCES) $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJ) $(EXE)
