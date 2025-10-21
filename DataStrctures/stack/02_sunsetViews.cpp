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

// Approach To solve this 
/*
    We will use stack to solve this problem,
        - Keep pushing elements(height of the buildings) into the stack
        - until a bigger element (building with greater height) than the last value in the stack appears or 
          we ran out of elements(complete the traversal)
            -  if the current building's height is greater than the top most element in the stack
            -  we keep poping the elements(building) from the stack until either we find a elment that 
                bigger or the stack is empty;

            - this way after the traversal of the entire array we would be left with only the indices that
             - a visible sunset from them.
             
             - we pop them and store the result in an array, 

             ----if the direction is WEST (sun is on the left of zeroth index we would start the stackifiation of the
                    array in the reverse order that is from n to zero instead of what we did for EAST (zeroth to n));
*/
int main(){
    return 0;
}