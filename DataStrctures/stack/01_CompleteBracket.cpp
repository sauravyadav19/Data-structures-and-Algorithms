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
        }else if (el == '}' || el == ']' || el == ')'){
            // In case the statement begins with one of the closing brackets
            // in that case we need to make sure we do not face error
            // as we would be trying to check top of the stack which will be empty
            if(bracketStack.empty()) return false;
            // Rest of the closing statements to make sure that the top of the stack is the opening of the current
            // bracket and make sure that there is no conditon like this is allowed [(]) as this is not valid
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
        }else{
            // in case there is alphabets, numbers or anything else in the string along with the brackets
            // we simply do not put them in the stack
            continue;
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

    string expression = ")ab(){dac[]";
    cout<< completenessEvaluator(expression);
    return 0;
}