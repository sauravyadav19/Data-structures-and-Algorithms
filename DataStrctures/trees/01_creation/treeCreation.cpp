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
        tree(Node* node): root(node){}
        void pushChildren(Node* parentNode,Node* child){
            parentNode->children.push_back(child);
        }
        // Creating a Display function: for showing the tree's level
        // eg: 10( 20 30 { -101 -102 } 40 { -102 } )
        // here 10 is the root level elemnet
        // 20 , 30 40 are root's children
        // and the elements listed in curly braces after an element is its children
        //                 10 (root [level 1])
        //          |      |        |
        //         20     30        40  [level 2]
        //               /  \       |
        //            -101  -102   -103 [level 3]

        void display(){
            cout<< root->data << "( " ;
            for(int i = 0; i < root->children.size(); i++){
                cout<< root->children[i]->data <<" ";
                if(root->children[i]->children.size()){
                    cout<< "{ ";
                    for(int j = 0; j < root->children[i]->children.size(); j ++){
                        cout<< root->children[i]->children[j]->data << " ";
                    }
                    cout<< "} ";
                }
            }
            cout<< ")" <<endl;;
        }
       

};
    
int main(){
    Node* root = new Node(10);
    Node* rootLevel1Child1 = new Node(20);
    Node* rootLevel1Child2 = new Node(30);
    Node* rootLevel1Child3 = new Node(40);
    Node* level2Child1 = new Node(-101);
    Node* level2Child2 = new Node(-102);
    Node* level2Child3 = new Node(-103);
   tree t = tree(root);
   t.pushChildren(root,rootLevel1Child1);
   t.pushChildren(root,rootLevel1Child2);
   t.pushChildren(root,rootLevel1Child3);
   t.pushChildren(rootLevel1Child2,level2Child1);
   t.pushChildren(rootLevel1Child3,level2Child3);
   t.pushChildren(rootLevel1Child2,level2Child2);
   t.display();
    return 0;
}