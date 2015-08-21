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

    cout << "\n****Running OR Gate****..." << endl;

    std::vector<Set> orSet = network.ORGate();
    cout << "\n****Running NAND Gate****..." << endl;

    std::vector<Set>nandSet = network.NANDGate();
    cout << "\n****Running AND Gate****..." << endl;
    network.ANDGate(orSet, nandSet);

    cout << "Program ended normally..." << endl;
    return 0;
}

