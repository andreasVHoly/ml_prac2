#ifndef PERCEPNETWORK_H
#define PERCEPNETWORK_H

#include "testset.h"
#include "perceptron.h"

namespace vhland002{
class PercepNetwork
{
public:
    PercepNetwork(TestSet set):set(set){}

    int runFunction(Perceptron node);

private:
    TestSet set;

};

#endif // PERCEPNETWORK_H
}
