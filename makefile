#makefile for Assignment 3, to encode a file with the huffman coding algorithm
#compiler name
CC=g++
#flags that need to be passed to the compiler
CCFLAGS=-std=c++11
#the libraries that are referenced
LIBS=-lm

prog:	main.o	
		$(CC)	$(CCFLAGS)	main.o set.o testset.o percepnetwork.o perceptron.o -o program $(LIBS)

set.o:	set.cpp
		$(CC) $(CCFLAGS) set.cpp -c

testset.o:	testset.cpp
		$(CC) $(CCFLAGS) testset.cpp -c

percepnetwork.o:	percepnetwork.cpp
		$(CC) $(CCFLAGS) percepnetwork.cpp -c


perceptron.o:	perceptron.cpp
		$(CC) $(CCFLAGS) perceptron.cpp -c

main.o:	main.cpp
		$(CC) $(CCFLAGS) main.cpp -c
	

run:
	./prog
#if we want to clean all the compiled files	
#to clean all .o files
#to clean the driver file which is used to run the program
clean:
		@rm -f *.o
		@rm -f program
