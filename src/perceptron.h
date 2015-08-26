#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include <cstdlib>
namespace vhland002{


class Perceptron
{
public:
    //CONSTRUCTOR//
    Perceptron(float learningRate)
        :learningRate(learningRate){}

    //METHODS//

    float getResult();
    void setInputs(int input1, int input2);
    void setWeights(float weight0, float weight1, float weight2);

    float recalculateWeight1();
    float recalculateWeight2();

    //SETTERS//
    void setWeight(float value);
    void setLearningRate(float rate);
    void setTarget(int target);
    void setInput(int input);
    void setOutput(int output);
    //GETTERS//
    float getWeight();
    float getLearningRate();
    int getTarget();
    int getInput();
    int getOutput();

    //VARS//
    float weight0, weight1, weight2, learningRate, result;
    int target, input1, input2, output;

};



}//vhland002
#endif // PERCEPTRON_H

