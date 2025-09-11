#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class MinMaxStack{
    private:
        vector<unordered_map <string,int>> minMaxStack = {};
        vector<int> stack = {};
    public:
        int peek(){
            return stack[stack.size() - 1];
        }
        int pop(){
            int result =  stack[stack.size() - 1];
            minMaxStack.pop_back();
            stack.pop_back();
            return result;
            
        }
        void push(int value){
            unordered_map<string,int> newMinMax = {{"min",value},{"max",value}};
            if(minMaxStack.size()){
                newMinMax["min"] = min(minMaxStack[minMaxStack.size() -1]["min"], value);
                newMinMax["max"] = max(minMaxStack[minMaxStack.size() - 1]["max"],value);
            }
            minMaxStack.push_back(newMinMax);
            stack.push_back(value);
        }
        void display(){
            for(auto &element: stack){
                cout<< element << " ";
            }
            cout<<endl;
        }
        void displayMinMax(){
            for( int i = 0; i < minMaxStack.size(); i++ ){
                cout<< "Index " << i << ": ";
                for(auto &element: minMaxStack[i]){
                    cout<< element.first << ":"<<element.second << " ";
                }
                cout<< endl;
            }
        }
        int getMax(){
            return minMaxStack[minMaxStack.size() - 1]["max"];

        }
        int getMin(){
            return minMaxStack[minMaxStack.size() - 1]["min"];

        }

};

int main(){
    MinMaxStack obj = MinMaxStack();
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.display();
    obj.pop();
    obj.display();
    obj.push(50);
    obj.push(2);
    obj.pop();
    obj.push(10);
    obj.display();
    cout<< "peek: " << obj.peek() <<endl;
    cout<< "max value: " << obj.getMax()<<endl;
    cout<< "min value: " << obj.getMin()<<endl;

    obj.displayMinMax();
    return 0;
}