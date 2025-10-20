#include<iostream>
#include <vector>
#include <climits>
using namespace std;

int minValue = INT_MIN;

ostream& operator<<(ostream& stream, vector<int> array){
    stream << "[ ";
    for(int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            stream<< array[i] ;
            continue;
        }
        stream<<array[i] << ", ";
    }
    stream  << " ]";
    stream<<endl;
    return stream;
}

void swap(int& num1, int&num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}


int getSmallestIndex(vector<int>&array){
    int index = 0;

    for(int i = 0; i < array.size(); i++){
        if(array[index] > array[i]){
            index = i;
        }
    }
    return index;
}

vector<int> threeLargestNumbers(vector<int>& array){
    vector<int> threeLargestValues = {minValue, minValue, minValue};
    int smallest = getSmallestIndex(threeLargestValues);

    for(int i = 0; i < array.size(); i++){
        if(array[i] > threeLargestValues[smallest]){
            threeLargestValues[smallest] = array[i];
            smallest = getSmallestIndex(threeLargestValues);
            continue;
        }
    }
    // using bubble Sort to sort the array at the end;
    // Bubble sort seems to be the appropriate choice here since its a an array with 3 values
    // and easier to implement
    for(int i = 0; i < threeLargestValues.size() - 1; i++){
        for(int j = 0; j < threeLargestValues.size() - i - 1; j++){
            if(threeLargestValues[j] > threeLargestValues[j+1] ){
                swap(threeLargestValues[j], threeLargestValues[j+1]);
            }
        }

    }
    return threeLargestValues;

}
int main(){
    vector<int> array = {141,1,17,-7,-17,-27,18,541,8,7,7};
    cout<< threeLargestNumbers(array);

    return 0;
}