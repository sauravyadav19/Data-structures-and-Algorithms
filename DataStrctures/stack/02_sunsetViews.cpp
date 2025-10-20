/*
    Objective : To find from which building we can see the sunset 
    Given : we will be given an array of height of the buildings and the direction which sun is in
            [3,5,4,4,3,1,3,2] , EAST (sun is at right side of the zeroth index)
    Visual representaion of this:
           ____
          |    |  ____   ____
     ___  |    | |    | |    |  ____         ____
    |   | |  5 | |  4 | |  4 | |    |       |    |   ___
    | 3 | |    | |    | |    | |  3 |  ____ | 3  |  | 2 |
    |___| |____| |____| |____| |____| |_1_| |____|  |___|

      0     1       2      3      4     5      6       7

    The sunset would be only visible from building at the indices 1,3,6,7 

    OUTPUT [1,3,6,7] in a sorted order

IN CASE THE Direction is WEST (sun is at the left of the zeroth Index)

           ____
          |    |  ____   ____
     ___  |    | |    | |    |  ____         ____
    |   | |  5 | |  4 | |  4 | |    |       |    |   ___
    | 3 | |    | |    | |    | |  3 |  ____ | 3  |  | 2 |
    |___| |____| |____| |____| |____| |_1_| |____|  |___|

      0     1       2      3      4     5      6       7

    the sunset would be only visible from building at the indeices 0,1


*/

#include <iostream>
#include <vector>
using namespace std;


// Helper function to print the stack in a formatted manner
ostream& operator<<(ostream& stream, stack<int> string ){
    stream<<endl;

    while(!string.empty()){
        stream << "|\t"<<string.top() << "\t|"<<endl;
        stream <<"|_______________|"<<endl;
        string.pop();
    }
    return stream;
}


int main(){
    return 0;
}