#include <iostream>
#include <vector>
using namespace std;

// Objective: 
// In our previous version of merge sort we were using a lot of addtional arrays and a lot of copying
// in this version we are improving on these "problems"


// Helper function to display array in a formatted manner (Same as version_1)
ostream& operator<< (ostream& stream, const vector<int>& array){
    stream<< "[ ";
    for(int i = 0; i < array.size(); i++){
        if(i == array.size()-1){
            stream << array[i];
        }
        else{
            stream << array[i] << ", ";
        }
    }
    stream << " ]";
    stream<<endl;
    return stream;
}

int main(){
    return 0;
}