EXECUTABLE=test
CC=g++

.PHONY: all clean

all: $(EXECUTABLE)
	rm -f *.o

$(EXECUTABLE): *.o
	$(CC) -o $@ $^

*.o : *.cpp
	$(CC) $^

clean:
	rm -f $(EXECUTABLE)
	rm -f *.o