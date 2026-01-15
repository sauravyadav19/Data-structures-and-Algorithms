#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void threeNumberSort(vector<T>& array, vector<T>& order){
    int firstCount = 0;
    T firstElement = order[0];

    int secondCount = 0;
    T secondElement = order[1];

    int thridCount = 0;
    T thirdElement = order[2];

    for(int i = 0; i < array.size(); i++){
        if(array[i] == firstElement){
            firstCount ++;

        }
        if(array[i] == secondElement){
            secondCount ++ ;

        }
        if(array[i] == thirdElement){
            thridCount++; 

        }

    }

    int i = 0;
    for(; i < firstCount; i++) array[i] = firstElement;


    int j = i;
    for(; j<i+secondCount;j++ )array[j] = secondElement;

    int k = j;
    for(; k < array.size(); k++)array[k] = thirdElement;
}


int main(){

    vector<char> array = {'A', 'A', 'B', 'A', 'C', 'B', 'C'};
    vector<char> order = {'C','B','A'};

    threeNumberSort(array,order);

    for(auto & i : array){
        cout<< i << " ";
    }
    return 0;
}