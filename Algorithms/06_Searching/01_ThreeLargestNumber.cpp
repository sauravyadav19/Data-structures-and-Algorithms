#include<iostream>
#include <vector>
using namespace std;

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

int main(){
    vector<int> array = {1,2,3,4,5,67};
    cout<< array;
    return 0;
}