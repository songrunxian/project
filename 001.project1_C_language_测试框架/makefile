.PHONY: clean

all: main.o runxian/test.o
	g++ -o ./bin/c_language main.o runxian/test.o

main.o: main.cpp
	g++ -I ./ -c main.cpp

runxian/test.o: runxian/test.h runxian/test.cpp
	g++ -I ./ -o runxian/test.o -c runxian/test.cpp

clean:
	rm -rf ./a.out *.o */*.o
