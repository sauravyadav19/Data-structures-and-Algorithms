#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class MinMaxStack{
    private:
        vector<int> stack = {};
    public:
        int peek(){
            return stack[stack.size() - 1];
        }
        int pop(){
            int result =  stack[stack.size() - 1];
            stack.pop_back();
            return result;
            
        }
        void push(int value){
             stack.push_back(value);
        }
        void display(){
            for(auto &element: stack){
                cout<< element << " ";
            }
            cout<<endl;
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
    obj.display();
    cout<< "peek: " << obj.peek() <<endl;
    return 0;
}