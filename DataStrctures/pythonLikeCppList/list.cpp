#include <iostream>
#include <vector>
#include <variant>
using namespace std;
struct Node;
using Element = variant<int,vector<Node>, bool>;
struct Node{
    Element value;
    Node(int v): value(v){}
    Node (bool v) : value(v){}
    Node(vector<Node>  v) : value(move(v)){}
    Node(initializer_list<Node> list) : value(vector<Node>(list)) {}
    
};
ostream& operator<< (ostream& stream, const Node &element){
        if(holds_alternative<int> (element.value)){
            stream << get<int>(element.value)<<", ";
        }
        else if (holds_alternative<bool>(element.value)){
        
            auto value =  get<bool>(element.value);

            if(value ==1){
                stream << "true ";
            }
            else{
                stream << "false ";
            }
        }
        else if (holds_alternative<vector<Node>>(element.value)){
            stream << "[ ";
            vector<Node> array = get<vector<Node>> (element.value);
            for(int i = 0; i < array.size(); i ++){
                auto el = array[i];
               stream <<  el << " ";
            }
            stream << "]";
        }
        else{
            stream << "WRONG";

        }
     return stream;
}
ostream& operator<< (ostream& stream, const vector<Node> & array){
    stream<< "[";
    for(size_t i = 0; i <array.size(); i++ ){
        stream << array[i];
    }
    stream << "]";
    return stream;
}

int main() {
   vector<Node> arrayOfNumbers = {5,{1,2,false},6,7,100,99,false};
   cout<< arrayOfNumbers;
}