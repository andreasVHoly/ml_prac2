#makefile for Assignment 3, to encode a file with the huffman coding algorithm
#compiler name
CC=g++
#flags that need to be passed to the compiler
CCFLAGS=-std=c++11
#the libraries that are referenced
LIBS=-lm

driver:	main.o	set.o	testset.o	percepnetwork.o	perceptron.o
		$(CC)	$(CCFLAGS)	set.o testset.o percepnetwork.o perceptron.o main.o -o driver $(LIBS)


set.o:	set.cpp	set.h
		$(CC) $(CCFLAGS) set.cpp -c

testset.o:	testset.cpp	testset.h
		$(CC) $(CCFLAGS) testset.cpp -c

percepnetwork.o:	percepnetwork.cpp	percepnetwork.h
		$(CC) $(CCFLAGS) percepnetwork.cpp -c


perceptron.o:	perceptron.cpp	perceptron.h
		$(CC) $(CCFLAGS) perceptron.cpp -c


main.o:	main.cpp
		$(CC) $(CCFLAGS) main.cpp -c
	


#if we want to clean all the compiled files	
#to clean all .o files
#to clean the driver file which is used to run the program
clean:
		@rm -f *.o
		@rm -f program
