#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>



namespace vhland002{


std::vector<Set> PercepNetwork::ORGate(){

    using namespace std;


    bool debug = false;



    srand(time(0));

    float weight0 = -0.5;

    double value = rand() % 1000;//random number
    float weight1 = value/1000.0f;
    if(debug)cout << "random weight1 is " << weight1 << endl;
    value = rand() % 1000;//random number
    float weight2 = value/1000.0f;
    if(debug)cout << "random weight1 is " << weight2<< endl;
    //weight1 = 0.840188f;
   // weight2 = 0.394383f;

    Set set1(1,1,1);
    Set set2(1,0,1);
    Set set3(0,1,1);
    Set set4(0,0,0);

    TestSet ORTable(4);
    ORTable.addSet(set1);
    ORTable.addSet(set2);
    ORTable.addSet(set3);
    ORTable.addSet(set4);

    int results[4];

    int count = 1;
    Perceptron node(0.1);
    while (true){

        for (int k = 0; k < 4; k++){
            //set target
            node.target = ORTable.sets[k].output;
            //set inputs
            node.setInputs(ORTable.sets[k].input1,ORTable.sets[k].input2);
            //set weights
            node.setWeights(weight0, weight1, weight2);
            //recalc weights
            weight1 = node.recalculateWeight1();
            weight2 = node.recalculateWeight2();

            //check result and write output
            if (node.getResult() > 0){
                results[k] = 1;
                if(debug)cout << "Result set to 1" << endl << endl;
            }
            else{
                results[k] = 0;
                if(debug)cout << "Result set to 0" << endl << endl;
            }

        }


        //check errors
        int error = 4;
        cout << "\nalg results" << endl;
        for (int l  = 0; l < 4; l++){

           cout << results[l] << " , ";
        }

        cout << "\ntable results" << endl;
        for (int p  = 0; p < 4; p++){

           cout << ORTable.sets[p].output << " , ";
        }


        cout << endl;
        for (int j  = 0; j < 4; j++){
            if(debug)cout << "comparing " << results[j] << " and " << ORTable.sets[j].output << endl;

            if (results[j] == ORTable.sets[j].output){
                if(debug)cout << ":TRUE" << endl;
                error--;
            }
            else{
                if(debug)cout << ":FALSE" << endl;
            }

        }


        cout << "\nIterations run: " <<  count << endl << endl/* << endl << endl*/;
        //cout << error << endl;
        if (error == 0){
            break;
        }
        count++;
    }
    return ORTable.sets;
}

std::vector<Set> PercepNetwork::NANDGate(){
    using namespace std;


    bool debug = false;



    srand(time(0));

    float weight0 = -2.0f;

    double value = rand() % 1000;//random number
    float weight1 = value/1000.0f;
    cout << "random weight1 is " << weight1 << endl;
    value = rand() % 1000;//random number
    float weight2 = value/1000.0f;
    cout << "random weight2 is " << weight2<< endl;
   // weight1 = 0.008401f;
   // weight2 = 0.003943f;

    Set set1(1,1,1);
    Set set2(1,0,0);
    Set set3(0,1,0);
    Set set4(0,0,0);

    TestSet ANDTable(4);
    ANDTable.addSet(set1);
    ANDTable.addSet(set2);
    ANDTable.addSet(set3);
    ANDTable.addSet(set4);

    int results[4];

    int count = 1;
    Perceptron node(0.1);
    while (true /*&& count < 10*/){

        for (int k = 0; k < 4; k++){
            //set target
            node.target = ANDTable.sets[k].output;
            //set inputs
            node.setInputs(ANDTable.sets[k].input1,ANDTable.sets[k].input2);
            //set weights
            node.setWeights(weight0, weight1, weight2);
            //recalc weights
            weight1 = node.recalculateWeight1();
            weight2 = node.recalculateWeight2();

            //check result and write output
            if (node.getResult() > 0){
                results[k] = 1;
                if(debug)cout << "Result set to 1" << endl << endl;
            }
            else{
                results[k] = 0;
                if(debug)cout << "Result set to 0" << endl << endl;
            }

        }


        //check errors
        int error = 4;
        cout << "\nalg results" << endl;
        for (int l  = 0; l < 4; l++){

           cout << results[l] << " , ";
        }

        cout << "\ntable results" << endl;
        for (int p  = 0; p < 4; p++){

           cout << ANDTable.sets[p].output << " , ";
        }


        cout << endl;
        for (int j  = 0; j < 4; j++){
            if(debug)cout << "comparing " << results[j] << " and " << ANDTable.sets[j].output << endl;

            if (results[j] == ANDTable.sets[j].output){
                if(debug)cout << ":TRUE" << endl;
                error--;
            }
            else{
                if(debug)cout << ":FALSE" << endl;
            }

        }


        cout << "\nIterations run: " <<  count << endl << endl/* << endl << endl*/;
        //cout << error << endl;
        if (error == 0){

            break;
        }


        count++;
    }

    cout << "\nFinal results" << endl;
    for (int y  = 0; y < 4; y++){
        if (results[y] == 1){
            results[y] = 0;
            cout << results[y] << " , ";
        }
        else{
            results[y] = 1;
            cout << results[y] << " , ";

        }

    }
    cout << endl << endl;
    return ANDTable.sets;

}

void PercepNetwork::ANDGate(std::vector<Set> OR, std::vector<Set> NAND){
    using namespace std;


    bool debug = false;



    srand(time(0));

    float weight0 = -0.8f;

    double value = rand()/double(RAND_MAX);//random number
    float weight1 = value;
    cout << "random weight1 is " << weight1 << endl;
    value = rand()/double(RAND_MAX);//random number
    float weight2 = value;
    cout << "random weight2 is " << weight2<< endl;
    weight1 = 0.00008f;
    weight2 = 0.00003f;

    Set set1(OR[0].output,NAND[0].output,0);
    Set set2(OR[1].output,NAND[1].output,1);
    Set set3(OR[2].output,NAND[2].output,1);
    Set set4(OR[3].output,NAND[3].output,0);

    TestSet XOR(4);
    XOR.addSet(set1);
    XOR.addSet(set2);
    XOR.addSet(set3);
    XOR.addSet(set4);

    int results[4];

    int count = 1;
    Perceptron node(0.1);
    while (true /*&& count < 20*/){

        for (int k = 0; k < 4; k++){
            //set target
            node.target = XOR.sets[k].output;
            //set inputs
            node.setInputs(XOR.sets[k].input1,XOR.sets[k].input2);
            //set weights
            node.setWeights(weight0, weight1, weight2);
            //recalc weights
            weight1 = node.recalculateWeight1();
            weight2 = node.recalculateWeight2();

            //check result and write output
            if (node.getResult() > 0){
                results[k] = 1;
                if(debug)cout << "Result set to 1" << endl << endl;
            }
            else{
                results[k] = 0;
                if(debug)cout << "Result set to 0" << endl << endl;
            }

        }
       // weight0 -= 0.01;

        //check errors
        int error = 4;
        cout << "\nalg results" << endl;
        for (int l  = 0; l < 4; l++){

           cout << results[l] << " , ";
        }

        cout << "\ntable results" << endl;
        for (int p  = 0; p < 4; p++){

           cout << XOR.sets[p].output << " , ";
        }


        cout << endl;
        for (int j  = 0; j < 4; j++){
            if(debug)cout << "comparing " << results[j] << " and " << XOR.sets[j].output << endl;

            if (results[j] == XOR.sets[j].output){
                if(debug)cout << ":TRUE" << endl;
                error--;
            }
            else{
                if(debug)cout << ":FALSE" << endl;
            }

        }


        cout << "\nIterations run: " <<  count << endl << endl/* << endl << endl*/;
        //cout << error << endl;
        if (error == 0){

            break;
        }


        count++;
    }

    cout << endl << endl;
}




}


