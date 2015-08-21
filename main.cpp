#include <iostream>
#include "perceptron.h"
#include "testset.h"
#include "percepnetwork.h"


int main(int argc, char * argv[])
{

    using namespace std;
    using namespace vhland002;
    cout << "Program started..." << endl;

    PercepNetwork network;

    cout << "\nRunning OR Gate..." << endl;

    std::vector<Set> orSet = network.ORGate();
    cout << "\nRunning NAND Gate..." << endl;

    std::vector<Set>nandSet = network.NANDGate();
    cout << "\nRunning XOR Gate..." << endl;
    network.ANDGate(orSet, nandSet);

    cout << "Program ended normally..." << endl;
    return 0;
}

