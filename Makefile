zoo_run:
	g++ zoo_tycoon.cpp zoo.cpp animal.cpp monkey.cpp sea_otter.cpp sloth.cpp -o zoo_run

CC=g++
EXE_FILE=zoo_run
all: $(EXE_FILE)
$(EXE_FILE): zoo_tycoon.cpp zoo.o animal.o monkey.o sea_otter.o sloth.o 
	$(CC) zoo_tycoon.cpp zoo.o animal.o monkey.o sea_otter.o sloth.o -o $(EXE_FILE)
zoo.o: zoo.cpp zoo.h
	$(CC) -c zoo.cpp
animal.o: animal.cpp animal.h
	$(CC) -c animal.cpp
monkey.o: monkey.cpp monkey.h
	$(CC) -c monkey.cpp
sea_otter.o: sea_otter.cpp sea_otter.h
	$(CC) -c sea_otter.cpp
sloth.o: sloth.cpp sloth.h
	$(CC) -c sloth.cpp

clean:
	rm -f *.o $(EXE_FILE)
