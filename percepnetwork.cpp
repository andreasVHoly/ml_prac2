#include "percepnetwork.h"



namespace vhland002{



int PercepNetwork::runFunction(float learningRate){
    using namespace std;
    cout << set.size() << endl;
    Perceptron node(learningRate,0);
    for (int i = 0; i < set.size(); i++){
        //create a new perceptron
        cout << "new perceptron created" << endl;

        node.setTarget(set[i].output);
        int iteration = 0;
       float output = 0;
        int checker = 0;
        while (checker < 10000000){
            cout << "looping" << endl;
            output = node.getInputs(set[i].input1, set[i].input2);
            cout << output << endl;
            node.output = output;
            if (output != node.target){
                node.recalculateWeight1();
                node.recalculateWeight2();
            }

            else{

                break;
            }
            cout << node.weight1 << endl;
            cout << node.weight2 << endl;
            checker++;
        }



//        while (node.recalculateWeight(set[i].output) != node.target){
//            cout << "calculating weights -> " << iteration << endl;
//            iteration++;
//        }
        cout << "Done" << endl;
        cout << "Weight is at " << node.weight1 << endl;
        cout << "Weight is at " << node.weight2 << endl;
    }

}

}


