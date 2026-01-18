// We are given an array of values that we want to sort and another array which tells us what order we would like our values to be sorted in.
// since this is a threeNumberSort, the "order" array which specifies in which order our values should sorted is consist of only three distinct values;
// For example {0,1,-1};
// this also implicitly convey that our "values" array cannot have any other distinct values, rather only multiple instances of the values in the "order" array.

//so the final understanding is that "values" array can have combination or permutation of set of the values in the "order" array 
// Example: order = {x,y,z} then "values" could be [x,z,z,y,z,x,...,z] or [y,z,x,x,z,y...z]  and so on..


// Naïve approach:
    // we create buckets/counter that keep track of how many times a particular value occur in the "values" array,since we know that there could only be three distinct value in the "values" array,so we only need to create three buckets/counter.
    // we traverse the array and we keep incrementing the corresponding values's bucket/counter;
    // after this we will know how many times a value has occured in the array
    // we could then traverse the "values" array and according to the count of each distinct values add its instance thus overwriting the previous array but now in the sorted form that "order" specifies.

// values = {0,1,-1,1,0,1,1,0,-1,1}
// order = {0,1,-1}
// After traversing array we would know:
    //  0 occurs 3 times
    //  1 occurs 5 times
    // -1 occurs 2 times
// we simply overwrite the array 
// {0,0,0,1,1,1,1,1,-1,-1}
// Time complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void threeNumberSort(vector<T>& values, vector<T>& order){
    int firstCount = 0;
    T firstElement = order[0];

    int secondCount = 0;
    T secondElement = order[1];

    int thridCount = 0;
    T thirdElement = order[2];

    for(int i = 0; i < values.size(); i++){
        if(values[i] == firstElement){
            firstCount ++;

        }
        if(values[i] == secondElement){
            secondCount ++ ;

        }
        if(values[i] == thirdElement){
            thridCount++; 

        }

    }

    int i = 0;
    for(; i < firstCount; i++) values[i] = firstElement;


    int j = i;
    for(; j<i+secondCount;j++ )values[j] = secondElement;

    int k = j;
    for(; k < values.size(); k++)values[k] = thirdElement;
}


int main(){

    vector<char> values = {'A', 'A', 'B', 'A', 'C', 'B', 'C'};
    vector<char> order = {'C','B','A'};

    threeNumberSort(values,order);

    for(auto & i : values){
        cout<< i << " ";
    }
    return 0;
}