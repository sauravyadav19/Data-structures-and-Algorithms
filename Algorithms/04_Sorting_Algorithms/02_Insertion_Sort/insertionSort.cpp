#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& array){
    return;
}

ostream& operator<<(ostream& stream, const vector<int>& array){
    cout<< "[ ";
    for(int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            stream << array[i];
        }
        else{
            stream << array[i] << ", ";
        }
    }
    cout<< " ]";
    cout<< endl;
    return stream;
}

int main(){

    vector<int> array = {8,5,2,9,5,6,3};
    cout<< array;
    return 0;
}