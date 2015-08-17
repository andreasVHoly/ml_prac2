#include "perceptron.h"

namespace vhland002{


float Perceptron::recalculateWeight(int input){
    weight = weight + (learningRate * input * target);
    return weight;
}








void Perceptron::setWeight(float value){
    this->weight = value;
}

void Perceptron::setLearningRate(float rate){
    this->learningRate = rate;
}

void Perceptron::setTarget(int target){
    this->target = target;
}

void Perceptron::setInput(int input){
    this->input = input;
}

void Perceptron::setOutput(int output){
    this->output = output;
}

float Perceptron::getWeight(){
    return weight;
}

float Perceptron::getLearningRate(){
    return learningRate;
}

int Perceptron::getTarget(){
    return target;
}

int Perceptron::getInput(){
    return input;
}

int Perceptron::getOutput(){
    return output;
}




}
