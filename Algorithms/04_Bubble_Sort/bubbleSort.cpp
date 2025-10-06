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
    bool swappedPerformed = false;
    for (int i = 0; i < array.size() - 1; i++){
        for (int j = 0; j < array.size()- i - 1; j++){
            if(array [j] > array[j+1]){
                swap (array[j], array[j+1]);
                swappedPerformed = true;
            } 
        }
        // In case there haven't been even a single swap
        // meaning the array is sorted
        if(!swappedPerformed){
            break;
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

    vector<int> array = {1,2,3,4,5,6,11,15};
    cout<< "Before Sorting : " << array;
    bubbleSort(array);
    cout<< "After Sorting :  "<< array;

    
    return 0;
}