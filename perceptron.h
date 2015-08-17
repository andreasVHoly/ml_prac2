#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <bitset>
namespace vhland002{


class Perceptron
{
public:
    //CONSTRUCTOR//
    Perceptron(float weight, float learningRate, int target)
        :weight(weight), learningRate(learningRate), target(target){}




    //METHODS//
    float recalculateWeight(int input);

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

private:
    //VARS//
    float weight, learningRate;
    int target, input, output;

};




#endif // PERCEPTRON_H
}//vhland002
