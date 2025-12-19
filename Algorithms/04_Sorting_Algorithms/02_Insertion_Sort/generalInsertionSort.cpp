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

int main(){

  return 0;
}