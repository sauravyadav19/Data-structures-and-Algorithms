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

template <typename T>
void insertionSort(vector<T> &array){
  for(unsigned int unsortedIndex = 1; unsortedIndex < array.size(); unsortedIndex ++){
   T valueToInsert = array[unsortedIndex];
   int compareIndex = unsortedIndex;
   while(array[compareIndex - 1] > valueToInsert && compareIndex > 0){
    array[compareIndex] = array[compareIndex - 1];
    compareIndex --;
   }
   array[compareIndex] =  valueToInsert;
  } 
  
  return;
}

int main(){

  // vector<char> array = {'c', 'm' , 'z', 'b', 'A', 'k'};
  vector<int> array = {9,3,7,1,10,5};
  // vector<float> array = {1.234, 2.24,2.22,0.8,-0.89,0.21,9.99,1.2};
  cout<< array<<endl;
  insertionSort(array);
  cout<< array<<endl;
  return 0;
}