#include "perceptron.h"
#include <iostream>

namespace vhland002{


float Perceptron::recalculateWeight1(){
    weight1 = weight1 + (learningRate * input * target);
    return weight1;
}

float Perceptron::recalculateWeight2(){
    weight2 = weight2 + (learningRate * input * target);
    return weight2;
}

float Perceptron::getInputs(int input1, int input2){
    using namespace std;
    double value = rand() % 10;//random number
    weight1 = value/10.0f;
    cout << "new weight1 is " << weight1 << endl;
    value = rand() % 10;//random number
    weight2 = value/10.0f;
    cout << "new weight2 is " << weight2 << endl;
    result = weight0 + weight1*input1 + weight2*input2;

    return result;

}








//void Perceptron::setWeight(float value){
//    this->weight = value;
//}

//void Perceptron::setLearningRate(float rate){
//    this->learningRate = rate;
//}

void Perceptron::setTarget(int target){
    this->target = target;
}

//void Perceptron::setInput(int input){
//    this->input = input;
//}

//void Perceptron::setOutput(int output){
//    this->output = output;
//}

//float Perceptron::getWeight(){
//    return weight;
//}

//float Perceptron::getLearningRate(){
//    return learningRate;
//}

//int Perceptron::getTarget(){
//    return target;
//}

//int Perceptron::getInput(){
//    return input;
//}

//int Perceptron::getOutput(){
//    return output;
//}




}
