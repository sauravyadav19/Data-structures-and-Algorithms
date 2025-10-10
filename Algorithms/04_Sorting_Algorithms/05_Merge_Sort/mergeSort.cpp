#include<iostream>
#include<vector>
using namespace std;

// Helper function to display array in a formatted manner
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

vector<int> merge(vector<int> firstArray, vector<int> secondArray){
    vector<int> result = {};
    if(firstArray.size () != 0 and secondArray.size() != 0){
       
        // making the pointer at the begining of the sorted Arrays
        int firstPointer = 0;
        int secondPointer = 0;

        while(firstPointer < firstArray.size() and secondPointer < secondArray.size()){

            // appending which ever elemet is the smallest and then moving the pointer to the next element
            if(firstArray[firstPointer] < secondArray[secondPointer]){
                result.push_back(firstArray[firstPointer]);
                firstPointer++ ;
            }
            else{
                result.push_back(secondArray[secondPointer]);
                secondPointer++;
                
            }
        }

        // in case the length of the array's do not match and one happens to be longer
        // we simply append all its element to the result vector
        if(firstPointer >= firstArray.size()){

            while(secondPointer < secondArray.size()){
                result.push_back(secondArray[secondPointer]);
                secondPointer++;
            }

        }
        else{
             while(firstPointer < firstArray.size()){
                result.push_back(firstArray[firstPointer]);
                firstPointer++;
            }
        }
    }
    else{
        // This part make sures that if either or both of the Arrays are empty we 
        // handle them properly and return the result accordingly
        if(firstArray.size() == 0 and secondArray.size() == 0){
            return {};
        }
        else if(firstArray.size() == 0){
            return secondArray;
        }
        else{
            return firstArray;
        }
    }

    return result;

}

vector<int> mergeSort(vector<int> array){
    // Base Case: in case their is only one element in the array we simply return that element
    if(array.size() == 1){
        return array;
    }

    // divide the array
    int mid = array.size()/2 ;

    // Left half
    vector<int> left;

    for(int i = 0; i < mid; i++){
        left.push_back(array[i]);
    }


    // right half
    vector <int> right;

    for(int i  = mid; i < array.size(); i ++){
        right.push_back(array[i]);
    }

    // Recursiverly dividing
    left = mergeSort(left);
    right = mergeSort(right);

    // merging the array
    return merge(left,right);

}

int main(){
    vector<int> array = {8,9,10,15,19,10,-1,0,9,7,14};
    cout<< "Before Sorting: " << array;
    cout<< "After Sorthing: " << mergeSort(array);
    return 0;
}