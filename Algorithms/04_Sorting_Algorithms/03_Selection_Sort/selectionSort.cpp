#include<iostream>
#include <vector>
using namespace std;

ostream& operator<<(ostream& stream, const vector<int>&array){
    cout<< "[ ";
    for(int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            cout<< array[i];
        }
        else{
            cout<< array[i] << ", ";
        }
    }
    cout<< " ]";
    cout<<endl;
    return stream;
}

void selectionSort(vector<int>& array){
    return;
}

int main(){

    vector<int> array = {9,1,8,2,-2,0,19,2,7};
    cout<< array;
    selectionSort(array);
    cout<< array;
    return 0;
    
}