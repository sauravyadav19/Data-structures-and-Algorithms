#include<iostream>
#include <vector>
using namespace std;


// Helper Function to Swap to values
void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void bubbleSort(vector<int>&array){
    for (int i = 0; i < array.size() - 1; i++){
        for (int j = 0; j < array.size()- i - 1; j++){
            if(array [j] > array[j+1]){
                swap (array[j], array[j+1]);
            } 
        }
    }
}

// Helper Function to display array properly
ostream& operator<< (ostream& stream, vector<int>& array){
    cout<< "[ ";
    for (int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            stream << array[i]<< " ]";
        }
        else{
            stream << array [i] << ", ";
        }
    }
    cout<<endl;
    return stream;
}

int main(){

    vector<int> array = {9,10,8,4,2,1,11,15,4};
    cout<< "Before Sorting : " << array;
    bubbleSort(array);
    cout<< "After Sorting :  "<< array;

    
    return 0;
}