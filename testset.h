#ifndef TESTSET_H
#define TESTSET_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set.h>
#include <cstdlib>

namespace vhland002{
class TestSet
{



public:
    TestSet(int size):size(size){}

    void readInTestSet(std::string filename);


private:
    int size;
    std::vector<vhland002::Set> sets;

};

#endif // TESTSET_H
}
