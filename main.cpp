#include <iostream>
#include "perceptron.h"
#include "testset.h"
#include "percepnetwork.h"


int main(int argc, char * argv[])
{

    using namespace std;
    using namespace vhland002;

    cout << "Program starting..." << endl;
//    int setSize = atoi(argv[1]);
//    string fileName = argv[2];
    int setSize = 4;
    string fileName = "test.txt";

    TestSet set(setSize);
    cout << "Reading in file " << fileName << endl;
    set.readInTestSet(fileName);



    PercepNetwork network(set.sets);
    network.runFunction(0.1f);


    cout << "Program ended normally" << endl;
    return 0;
}

