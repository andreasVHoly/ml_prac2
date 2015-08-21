#ifndef PERCEPNETWORK_H
#define PERCEPNETWORK_H

#include "testset.h"
#include "perceptron.h"
#include "set.h"

namespace vhland002{
class PercepNetwork
{
public:


    std::vector<Set> ORGate();
    std::vector<Set> NANDGate();
    void ANDGate(std::vector<Set> OR, std::vector<Set> NAND);



    int runFunction(float learningRate);

    std::vector<Set> set;

};
}//vhland002
#endif // PERCEPNETWORK_H

