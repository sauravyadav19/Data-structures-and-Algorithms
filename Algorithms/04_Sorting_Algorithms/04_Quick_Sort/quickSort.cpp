#include<iostream>
#include<vector>
using namespace std;

ostream& operator<<(ostream& stream, const vector<int>&array);

void swap(int& num1, int&  num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int partitioner(vector<int>& array,int low, int high){

    int piviot = array[(low + high)/ 2]; // Middle Most value
    int left = low;
    int right = high;

    while(true){
        // Finds the value that is suppose to be on the right side in the left side
        while(array[left] < piviot){
            left++;
        }
        // Finds the value that is suppose to be on the left side in the right side
        while(array[right] > piviot){
            right--;
        }
        // If left and right pointers have crossed each other or they are pointing at the same
        // location, return that index
        // this index would be used to divide the array
        if(left >=right){
            return right;
        }
        // Swap those values 
        swap(array[left], array[right]);
        // move the pointers one step towards each other
        left ++;
        right--;
    }

}

void quickSortHelper(vector<int>& array, int low,int high){
    // As long as the value of the lower index is smaller than that of higher one
    if(low < high){
        // this is the index where we would partition the array
        int mid = partitioner(array,low,high);
        // Individually sorting each half
        quickSortHelper(array,low,mid);
        quickSortHelper(array,mid + 1,high);
    }
}

void quickSort(vector<int>& array){
    quickSortHelper(array,0,array.size()- 1);
}
ostream& operator<<(ostream& stream, const vector<int>& array){
    stream<< "[ ";
    for(int i = 0; i<array.size(); i++){
        if(i == array.size() - 1){
            stream<< array[i];
        }
        else{
            stream << array[i]<< ", ";
        }
    }
    stream<< " ]"<<endl;
    return stream;
}

int main(){

    vector<int> array = {8,3,7,6,2,5,4,-1,2};
    cout<< array;
    quickSort(array);
    cout<<array;

    return 0;
}