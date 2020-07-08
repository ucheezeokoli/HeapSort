CC = g++

all:
	$(CC) -std=c++11 -o a.exe HeapSort.cpp

clean:
	rm -f a.exe

