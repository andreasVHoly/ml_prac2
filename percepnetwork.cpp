#include "percepnetwork.h"



namespace vhland002{



int PercepNetwork::runFunction(float learningRate){
    for (int i = 0; i < ; i++){
        //create a new perceptron
        Perceptron node(0.5f, learningRate,set[i].output);

        int iteration = 0;
        while (node.recalculateWeight(set[i].output) != set[i].target){
            cout << "calculating weights -> " << iteration << endl;
            iteration++;
        }
        cout << "Done" << endl;
        cout << "Weight is at " << node.weight << endl;
    }

}

}


