#include <iostream>
#include <vector>
using namespace std;

ostream& operator<< (ostream&stream, const vector<int>& array);

void insertionSort(vector<int>& array){
    for (int unsortedIndex = 1; unsortedIndex < array.size(); unsortedIndex++){

        int valueToInsert = array[unsortedIndex];
        int compareIndex= unsortedIndex;

        // Shifting the sorted array to the right element by element 
        // until we find the correct position for our 'value-to-be-inserted'
        while(compareIndex > 0 && array[compareIndex -1] > valueToInsert){
            array[compareIndex] = array[compareIndex-1];
            compareIndex--;
        }
        // Inserting it to the correct place in the sorted array
        array[compareIndex] = valueToInsert;
    }
    return;
}

ostream& operator<<(ostream& stream, const vector<int>& array){
    cout<< "[ ";
    for(int i = 0; i < array.size(); i++){
        if(i == array.size() - 1){
            stream << array[i];
        }
        else{
            stream << array[i] << ", ";
        }
    }
    cout<< " ]";
    cout<< endl;
    return stream;
}

int main(){

    vector<int> array = {8,5,2,0,9,-1,0,1,8,2};
    cout<< "Before Sorting :" << array;
    insertionSort(array);
    cout<< "After Sorting :" << array;
    return 0;
}