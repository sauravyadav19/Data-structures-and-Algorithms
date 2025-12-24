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

void mergeSort(vector<int>& src, vector<int>& dest, int low, int high){

  if(high - low <=1 ){
    dest[low] = src[low];
    return;
  }
 int mid = low + (high-low)/2;
  mergeSort(dest,src,low,mid); // this is where the buffer switches
  mergeSort(dest,src,mid,high);
  merge(src,dest,low,mid,high);
  cout<< "low - "<< low << " mid - " << mid << " high - " << high << endl;
  cout<< "src:  " <<&src <<"\t" <<src <<endl;
  cout<< "dest: "<< &dest<<"\t"<< dest << endl;
  cout<< "--------------------------------"<<endl;
    
}


int main(){

  vector<int> array = {4,1,7,2,9,10,5,3};
  vector<int> auxillaryArray(array.size());
  auxillaryArray = array;
  cout<< "A: "<< &array <<"\t" << "B: " << &auxillaryArray<<endl;
  cout<<"--------------------------------------------------"<<endl;
  mergeSort(array,auxillaryArray,0,array.size());
  cout<<auxillaryArray<<endl;
  return 0;
  
}