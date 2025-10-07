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

// Helper function to reterive the Index of the smallest number in the array
// starting from the index specifed as the argument
unsigned int minIndex(vector<int>& array,int startIndex){
    int indexWithMinValue = startIndex;
    for(int i = startIndex; i < array.size();i++){
        if(array[i] < array[indexWithMinValue]){
            indexWithMinValue = i;
        }
    }

    return indexWithMinValue;
    
}

void swap(int& num1, int& num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void selectionSort(vector<int>& array){

    for(int i = 0; i < array.size(); i++){
        int index = minIndex(array,i);
        swap(array[i], array[index]);
    }
    return;
}

int main(){

    vector<int> array = {9,1,8,2,-2,0,19,2,7};
    cout<< "Before Sorting: "<<  array;
    selectionSort(array);
    cout<<"After Sorting : " << array;
    return 0;

}