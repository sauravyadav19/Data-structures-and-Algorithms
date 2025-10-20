#include<iostream>
#include<vector>
#include <string>
#include <stack>
using namespace std;

ostream& operator<<(ostream& stream, stack<char> string ){
    stream<<endl;

    while(!string.empty()){
        stream << "|\t"<<string.top() << "\t|"<<endl;
        stream <<"|_______________|"<<endl;
        string.pop();
    }
    return stream;
}

bool completenessEvaluator(string expression){
    stack<char> bracketStack;
    
    for(auto el: expression){
        if(el == '{' || el == '[' || el == '('){
            bracketStack.push(el);
        }else{
            if(el == '}'){
                if(bracketStack.top() == '{'){
                    bracketStack.pop();
                }else{
                    return false;
                }

            }
            else if (el == ']'){
                if(bracketStack.top() == '['){
                    bracketStack.pop();
                }
                else{
                    return false;
                }

            }
            else if (el == ')'){
                if(bracketStack.top() == '('){
                    bracketStack.pop();
                }else{
                    return false;
                }

            }
            else{
                cout<< "rouge condition "<< endl;
                return false;
            }
        }
    }
    if(bracketStack.empty()){
        return true;
    }
    else{
        return false;
    }

}
 
int main(){

    string expression = "";
    cout<< completenessEvaluator(expression);
    return 0;
}