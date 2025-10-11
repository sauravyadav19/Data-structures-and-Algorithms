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

void merge(vector<int>& array, unsigned int low, unsigned int mid, unsigned int high){

    vector<int> sorted = {};
    unsigned int leftPointer = low;
    unsigned int rightPointer = mid + 1;

    while( leftPointer <= mid && rightPointer <= high){
        if(array[leftPointer] < array[rightPointer]){
            sorted.push_back(array[leftPointer]);
            leftPointer ++;
        }
        else{
            sorted.push_back(array[rightPointer]);
            rightPointer++;
        }
    }
    if(leftPointer >= mid and rightPointer <= high ){
        while(rightPointer<= high){
            sorted.push_back(array[rightPointer]);
            rightPointer++;
        }
    }else{
        while(leftPointer <= mid){
            sorted.push_back(array[leftPointer]);
            leftPointer++;
        }
    }

    for(int i = low; i <= high; i++){
        array[i] = sorted[i];
    }
}

int main(){
    vector<int> array = {3,8,9,7,10,12};
    cout<< array;
    merge(array,0,2,5);
    cout<< array;
    return 0;
}