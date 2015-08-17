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
    }
}


}


