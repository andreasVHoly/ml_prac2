#ifndef PERCEPNETWORK_H
#define PERCEPNETWORK_H

#include "testset.h"
#include "perceptron.h"
#include "set.h"

namespace vhland002{
class PercepNetwork
{
public:
    PercepNetwork(std::vector<Set> set):set(set){}

    int runFunction(float learningRate);

    std::vector<Set> set;

};
}//vhland002
#endif // PERCEPNETWORK_H

