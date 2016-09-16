# ml_prac2

README for the second machine learning practical

VHLAND002 - Andreas von Holy

Files Submitted:
percepnetwork.h
percepnetwork.cpp
set.h
testset.h
testset.cpp
perceptron.h
perceptron.cpp
main.cpp
README.txt
makefile



Answers to Questions:

1) 3 Perceptrons, 1 Perceptron for the OR Gate, 1 for the NAND Gate and both of these connect to the XOR Gate which uses the OR and NAND gate as input.

2) I used 3 training examples, see listed below
Training example for the OR Gate:

1,1, 1
1,0, 1
0,1, 1
0,0, 0



Training example for the AND Gate that gets converted to a NAND Gate ( see next table):

1,1, 1
1,0, 0
0,1, 0
0,0, 0

Converted NAND Gate:


1,1, 0
1,0, 1
0,1, 1
0,0, 1


Training example for the final XOR Gate  (catually and AND Gate from the outputs of the OR and NAND Gate):

OR[0].output,NAND[0].output, 0);
OR[1].output,NAND[1].output, 1);
OR[2].output,NAND[2].output, 1);
OR[3].output,NAND[3].output, 0);




Instructions:

1. In command window go to the directory with the files in.
2. Type 'make' to build the files.
3. Type 'make run' to run the program and sufficient output will show up.
4. Type 'make clean' to clean compiled files.
