#include<iostream>
#include<vector>
#include <string>
#include <stack>
using namespace std;

ostream& operator<<(ostream& stream, stack<char>& string ){
    stream<<endl;

    while(!string.empty()){
        stream << "|\t"<<string.top() << "\t|"<<endl;
        stream <<"|_______________|"<<endl;
        string.pop();
    }
    return stream;
}
 
int main(){

    string expression = "{()}{}";
    return 0;
}