#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    vector<Node*> children;
    Node(int data):data(data){}
};

class tree {
    private:
        Node * root;
    public:
        tree(): root(nullptr){}
        tree(Node* root):root(root){}

        //Method Declaration
        vector<int>& dfs(Node* node, vector<int>& result);
        vector<int>& dfs(vector<int>& result);

        void addChild(Node* parentNode, Node* childNode){
            parentNode->children.push_back(childNode);
        }
        void addChildren(Node*parentNode, initializer_list<Node*>children){
            for(Node* child: children){
                parentNode->children.push_back(child);
            }
        }
};

// When we want to expliclity traverse a node (usefull if we want to travserse a sub-tree)
vector<int>& tree::dfs(Node* node, vector<int>& result){

    // push the Data part of the Node into the Result Array
    result.push_back(node->data);
    // (Base Case) If the There is no children that is the Node is a leaf Node we return;
    if(node->children.empty()){
        return result;
    }else{
        //else we recursievely visit every node
        for(Node* i: node->children){
             dfs(i,result);
        }
    }
    // return the result (by reference)
    return result;

}
// When we want to traverse the entire tree, hence starting node is ROOT
vector<int>& tree::dfs(vector<int>& result){
    return dfs(this->root,result);
}



int main(){

    //Level 1
    Node* root = new Node(1);
    //Level 2
    Node* level2Child_1 = new Node(2);
    Node* level2Child_2 = new Node(3);
    Node* level2Child_3 = new Node(4);

    //Level 3
    Node* level3Child_1 = new Node(5);
    Node* level3Child_2 = new Node(6);
    Node* level3Child_3 = new Node(7);

    //Level 4
    Node* level4Child_1 = new Node(8);
    Node* level4Child_2 = new Node(9);

    //Level 5
    Node* level5Child_1 = new Node(10);

    //Level 6
    Node* level6Child_1 = new Node(11);
    Node* level6Child_2 = new Node(12);
    Node* level6Child_3 = new Node(13);
// we want to create a tree like this 
/*
                    1                           ---Level 1   {1}
              /     |     \
            2       3      4                    ---Level 2   {2,3,4}
          /   \            |
         5    6             7                   ---Level 3   {5,6,7}
                           / \
                          8   9                 ---Level 4   {8,9}
                          |
                          10                    ---Level 5   {10}
                        /  |  \
                       11  12 13                ---Level 6   {11,12,13}
*/

    // creating a tree by initalizing it with root Node

    tree* t = new tree(root);

    // now creating the parent-child relations:

    t->addChildren(root,{level2Child_1,level2Child_2,level2Child_3}); 
    t->addChildren(level2Child_1,{level3Child_1,level3Child_2});
    t->addChild(level2Child_3,level3Child_3);
    t->addChildren(level3Child_3,{level4Child_1,level4Child_2});
    t->addChild(level4Child_1,level5Child_1);
    t->addChildren(level5Child_1,{level6Child_1,level6Child_2,level6Child_3});


    vector<int> result = {};
    t->dfs(result);

    for(int&i : result){
        cout<< i << " ";
    }
    cout<<endl;

    return 0;
}