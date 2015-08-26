#include "perceptron.h"
#include <iostream>

namespace vhland002{

using namespace std;


//NOTE: cout statements are there for debugging, commented out for now

float Perceptron::recalculateWeight1(){
    weight1 += (learningRate * input1 * target);
    //cout << "new weight2 is " << weight1 << endl;
    return weight1;
}

float Perceptron::recalculateWeight2(){
    weight2 += (learningRate * input2 * target);
    //cout << "new weight2 is " << weight2 << endl;
    return weight2;
}

float Perceptron::getResult(){

    result = weight0 + weight1*input1 + weight2*input2;
    //cout << "result is " << result << endl;
    return result;

}




void Perceptron::setWeights(float weight0, float weight1, float weight2){
    this->weight0 = weight0;
    this->weight1 = weight1;
    this->weight2 = weight2;
    //cout << "weight0  set to " << this->weight0 << endl;
    //cout << "weight1  set to " << this->weight1 << endl;
    //cout << "weight2  set to " << this->weight2 << endl;
}

void Perceptron::setInputs(int input1, int input2){
    this->input1 = input1;
    this->input2 = input2;
//    cout << "input1  set to " << this->input1 << endl;
//    cout << "input2  set to " << this->input2 << endl;

}


void Perceptron::setTarget(int target){
    this->target = target;
}



}
