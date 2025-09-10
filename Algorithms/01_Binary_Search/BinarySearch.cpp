#include<iostream>
#include <vector>
using namespace std;

int binarySearchHelper(vector<int> array, int target, int leftPointer, int rightPointer){
    if(leftPointer > rightPointer){
        return -1;
    }
    int midPointer = (leftPointer + rightPointer)/2;
    if(array[midPointer] == target){
        return midPointer;
    }
    if(target > array[midPointer]){
        return binarySearchHelper(array,target,midPointer+1,rightPointer);
    }
    if(target < array[midPointer]){
       return binarySearchHelper (array,target,leftPointer,midPointer-1);
    }
    return -1;

}
int binarySearch(vector<int> array, int target ){
    return binarySearchHelper(array,target,0,array.size() -1);
}

int main(){
    vector<int> array = {1,2,3,4,5,6,7,8,9,10};
    cout<< binarySearch(array,4);
    return 0;
}