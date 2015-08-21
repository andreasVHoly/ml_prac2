#include "testset.h"
namespace vhland002{


void TestSet::readInTestSet(std::string filename){

    //we set the size of each training example


    using namespace std;

    string line;
    ifstream file(filename.c_str());

    //we check to see if the file is open
    if(file.is_open()){
        //we read data while we have data
        while(getline(file,line)){

            if (line[0] == '#'){
                //comment line
                continue;
            }
            else{
                istringstream ss1(line);
                string value;
                int i = 0;
                int temp[3];
                while (getline(ss1,value,',')){
                    temp[i] = atoi(value.c_str());
                    i++;
                }//while
                Set set(temp[0], temp[1], temp[2]);
                sets.push_back(set);
            }//else
        }//while
    }//if
    else{
        cout << "File read error" << endl;
        return;
    }
    cout << "Test set read in (input 1, input 2, output): " << endl;
    for (int i = 0; i < sets.size(); i++){
        cout << "Case " << i+1 << ": ";
        cout << sets[i].input1 << ", ";
        cout << sets[i].input2 << ", ";
        cout << sets[i].output << endl;
    }

}

void TestSet::addSet(Set set){
    sets.push_back(set);
}


}


