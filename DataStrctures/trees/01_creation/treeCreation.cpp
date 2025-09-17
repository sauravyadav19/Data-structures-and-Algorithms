#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    vector<Node*> children;
    Node(int data) : data(data), children({}){}
};

class tree{
    private:
        Node* root;
    public:
        tree(): root(nullptr){}
        tree(Node* node): root(node){}
        void pushChildren(Node* parentNode,Node* child){
            parentNode->children.push_back(child);
        }
        void display(){
            cout<< root->data << " --children--> " ;
            for(int i = 0; i < root->children.size(); i++){
                cout<< root->children[i]->data <<" ";
            }
        }

};
    
int main(){
    Node* root = new Node(10);
    Node* rootLevel1Child1 = new Node(20);
    Node* rootLevel1Child2 = new Node(30);
    Node* rootLevel1Child3 = new Node(40);
   tree t = tree(root);
   t.pushChildren(root,rootLevel1Child1);
   t.pushChildren(root,rootLevel1Child2);
   t.pushChildren(root,rootLevel1Child3);
   t.display();
    return 0;
}