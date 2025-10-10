#include<iostream>
#include<vector>
using namespace std;

// Helper function to display array in a formatted manner
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
    vector<int> array = {8,5,2,9,6,7,1};
    cout<< array;
    return 0;
}