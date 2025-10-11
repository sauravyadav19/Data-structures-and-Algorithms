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

    // Pointers to both sides of "array"
    unsigned int leftPointer = low;
    unsigned int rightPointer = mid + 1;
    // Comparing the elements 
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

    // copying the leftovers
    while(rightPointer<= high){
        sorted.push_back(array[rightPointer]);
        rightPointer++;
    }
    while(leftPointer <= mid){
        sorted.push_back(array[leftPointer]);
        leftPointer++;
    }

    // copying the value from temporary array to our actual array
    for(int i = 0; i < sorted.size(); i++){
        // our temp array starts from zero but it will happen that 
        // our actual array does not so finding the correct position using low +i
        array[low+i] = sorted[i];
    }
}

void mergeSortHelper(vector<int>& array,int left, int right){

    // Base case in case the pointer crossed
    if(left >= right ){
        return;
    }
    // finding the mid value
    int mid = (left + right) / 2;
    // recursively dividing the array
    mergeSortHelper(array,left,mid);
    mergeSortHelper(array,mid + 1,right);
    // merging the sorted parts
    merge(array,left,mid,right);

}

void mergeSort(vector<int>& array){
    mergeSortHelper(array,0,array.size() - 1);
}
int main(){
    vector<int> array = {9,-1,0,4,7,11,3,6,7};
    cout<< "Before Sorting : " << array;
    mergeSort(array);
     cout<< "After Sorting : " << array;
    return 0;
}