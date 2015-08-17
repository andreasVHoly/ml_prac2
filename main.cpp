#include <iostream>
#include "perceptron.h"
#include "testset.h"


int main(int argc, char * argv[])
{

    using namespace std;
    using namespace vhland002;


//    int setSize = atoi(argv[1]);
//    string fileName = argv[2];
    int setSize = 4;
    string fileName = "test.txt";

    TestSet set(setSize);
    set.readInTestSet(fileName);


    cout << "End" << endl;
    return 0;
}

