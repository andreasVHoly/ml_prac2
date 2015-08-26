#include "percepnetwork.h"
#include "testset.h"
#include "set.h"
#include <iostream>
#include <ctime>



namespace vhland002{


std::vector<Set> PercepNetwork::ORGate(){
    using namespace std;

    //ensures random values at start for each time we get random values
    srand(time(0));
    //we set out eright 0
    float weight0 = -0.5;
    //we assign random weights to weight1 & 2
    double value = rand() % 1000;//random number
    float weight1 = value/1000.0f;
    if(debug)cout << "random weight1 is " << weight1 << endl;

    value = rand() % 1000;//random number
    float weight2 = value/1000.0f;
    if(debug)cout << "random weight1 is " << weight2<< endl;

    //we create the sets
    Set set1(1,1,1);
    Set set2(1,0,1);
    Set set3(0,1,1);
    Set set4(0,0,0);

    //we create a table out of the sets
    TestSet ORTable(4);
    ORTable.addSet(set1);
    ORTable.addSet(set2);
    ORTable.addSet(set3);
    ORTable.addSet(set4);

    //the results that our program produces over time
    int results[4];

    int count = 1;
    Perceptron node(0.1);
    // we loop until we have minimized the error
    while (true){
        cout << endl << "Running iteration " << count << "...." << endl;
        //we loop through our data set (4 sets)
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


        //we print out what the algorithm is porducing and what the results should be
        cout << "\nalg results" << endl;
        for (int l  = 0; l < 4; l++){
            cout << results[l] << " , ";
        }
        cout << "\ntable results" << endl;
        for (int p  = 0; p < 4; p++){

           cout << ORTable.sets[p].output << " , ";
        }


        cout << endl;

        //we check for errors and break out if we have got it right
        int error = 4;
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



        //if we have no errors we break out of the while loop
        if (error == 0){
            cout << "\nIterations run for OR Gate: " <<  count << endl << endl;
            break;
        }
        count++;
    }
    //we return the answer we just got
    return ORTable.sets;
}

std::vector<Set> PercepNetwork::NANDGate(){

    ///NOTE: in this method we calculate a AND gate and switch the inputs in the end to get the NAND result


    using namespace std;
    srand(time(0));
    //assign weight 0
    float weight0 = -2.0f;
    //random weights
    double value = rand() % 1000;//random number
    float weight1 = value/1000.0f;
    if(debug)cout << "random weight1 is " << weight1 << endl;
    value = rand() % 1000;//random number
    float weight2 = value/1000.0f;
    if(debug)cout << "random weight2 is " << weight2<< endl;

    //we setup the test cases
    Set set1(1,1,1);
    Set set2(1,0,0);
    Set set3(0,1,0);
    Set set4(0,0,0);

    //make a test set
    TestSet ANDTable(4);
    ANDTable.addSet(set1);
    ANDTable.addSet(set2);
    ANDTable.addSet(set3);
    ANDTable.addSet(set4);

    int results[4];

    int count = 1;
    //set up a new perceptron with a learning rate of 0.1
    Perceptron node(0.1);
    while (true){
        cout << endl << "Running iteration " << count << "...." << endl;
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
        if (error == 0){
             cout << "\nIterations run for NAND Gate: " <<  count << endl << endl;
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
        ANDTable.sets[y].output = results[y];

    }
    cout << endl << endl;
    //return the nand results
    return ANDTable.sets;

}

void PercepNetwork::ANDGate(std::vector<Set> OR, std::vector<Set> NAND){
    using namespace std;
    srand(time(0));
    //assign weight 0
    float weight0 = -1.2f;
    //assign random weight 1 nd 2
    double value = rand()/double(RAND_MAX);//random number
    float weight1 = value;
    if(debug)cout << "random weight1 is " << weight1 << endl;
    value = rand()/double(RAND_MAX);//random number
    float weight2 = value;
    if(debug)cout << "random weight2 is " << weight2<< endl;

    //create set from the or gate results and the nand gate results
    Set set1(OR[0].output,NAND[0].output,0);
    Set set2(OR[1].output,NAND[1].output,1);
    Set set3(OR[2].output,NAND[2].output,1);
    Set set4(OR[3].output,NAND[3].output,0);

    //assign testset
    TestSet XOR(4);
    XOR.addSet(set1);
    XOR.addSet(set2);
    XOR.addSet(set3);
    XOR.addSet(set4);

    int results[4];

    int count = 1;
    Perceptron node(0.1);
    while (true){
        cout << endl << "Running iteration " << count << "...." << endl;
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
        if (error == 0){
             cout << "\nIterations run for XOR Gate: " <<  count << endl;
            break;
        }
        count++;
    }

    cout << endl << endl;
}

}//namespace


