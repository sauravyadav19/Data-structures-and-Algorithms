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

void completenessEvaluator(string expression){
    stack<char> bracketStack;
    
    for(auto el: expression){
        if(el == '{' || el == '[' || el == '('){
            bracketStack.push(el);
            cout<< bracketStack <<endl;
        }else{
            if(el == '}'){
                if(bracketStack.top() == '{'){
                    bracketStack.pop();
                    cout<< bracketStack<<endl;
                }else{
                    cout<< "Bracket Overlap condition"<<endl;
                    return;
                }

            }
            else if (el == ']'){
                if(bracketStack.top() == '['){
                    bracketStack.pop();
                    cout<< bracketStack<<endl;
                }
                else{
                    cout<<"Bracket Overlap"<<endl;
                    return;
                }

            }
            else if (el == ')'){
                if(bracketStack.top() == '('){
                    bracketStack.pop();
                    cout<< bracketStack<<endl;
                }else{
                    cout<< "Bracket Overlap"<<endl;
                    return;
                }

            }
            else{
                cout<< "some rouge condition "<< endl;
                return;
            }
        }
    }
    if(bracketStack.empty()){
        cout<< "Complete Bracket Expression"<<endl;
    }
    else{
        cout<< "Incomplete" <<endl;
        cout<< bracketStack;
    }

}
 
int main(){

    string expression = "[{()}]";
    completenessEvaluator(expression);
    return 0;
}