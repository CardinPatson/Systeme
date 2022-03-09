### 
## Makefile skeleton
## INFO0030: Projet 1
## 
### 

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

# Files
EXEC=pnm
MODULES=src/main.c libs/pnm.c
OBJECTS=bin/main.o bin/pnm.o

## Rules

all: $(EXEC)

pnm: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

main.o: src/main.c
	$(CC) -c src/main.c -o bin/main.o $(CFLAGS)

pnm.o: pnm.c
	$(CC) -c libs/pnm.c -o bin/pnm.o $(CFLAGS)

clean:
	rm -f bin/*.o $(EXEC) *~

