#include<iostream>
#include<vector>
using namespace std;

template < typename A>
ostream& operator<<(ostream& stream, const vector<A>& array){
  stream << "[ ";
  for(int i = 0; i < array.size(); i++){
    if(i == array.size() - 1){
      stream << array[i];
    }else{
      stream << array [i]<< ", ";
  } 
  }
  stream << " ]"; 
  return stream;
}

void merge(vector<int>& array, vector<int>& auxillaryArray, int low, int mid, int high ){

     int pt1= low;
     int pt2 = mid;
     int auxI = low;
     
     
     while(pt1 < mid && pt2 < high){
        if(array[pt1] <=  array[pt2]){
            auxillaryArray[auxI] = array[pt1];
            pt1++;
        }
        else{
            auxillaryArray[auxI] = array[pt2];
            pt2++;
        }
        auxI++;
     }
    while(pt1< mid){
        auxillaryArray[auxI] = array[pt1];
        auxI++;
        pt1++;
    }

    while(pt2 < high){
        auxillaryArray[auxI] = array[pt2];
        auxI++;
        pt2++;
    }
 
}


int main(){
    return 0;
}