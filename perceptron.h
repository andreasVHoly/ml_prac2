#ifndef PERCEPTRON_H
#define PERCEPTRON_H


#include <cstdlib>
namespace vhland002{


class Perceptron
{
public:
    //CONSTRUCTOR//
    Perceptron(float learningRate, int target)
        :learningRate(learningRate), target(target){}







    //METHODS//

    float getInputs(int input1, int input2);

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
    float weight0 = -0.5f, weight1, weight2, learningRate, result;
    int target, input, output;

};



}//vhland002
#endif // PERCEPTRON_H

