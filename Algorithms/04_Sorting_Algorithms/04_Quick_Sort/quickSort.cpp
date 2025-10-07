#include<iostream>
#include<vector>
using namespace std;


int main(){

    vector<int> array = {8,3,7,6,2,5,4};
    for(int& element: array) cout<< element << " ";
    quickSort(array);
    for(int& element: array) cout<< element << " ";


    return 0;
}