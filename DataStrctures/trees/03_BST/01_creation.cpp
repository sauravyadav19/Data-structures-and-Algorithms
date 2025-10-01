/*
    * In arrays, Binary Search cost us O((log n)) but insertion and deletion is costly (shifting of Element)
    * In Linked List, The insertion and Deletion is easy but the traversal itself cost us O(n)

    * To overcome their individual challanges and get the best of the world, that is 
        => Searching is easy 
        => Insertion and Deletion is easy
    * The new Data strcture that has both of these properties is Binary Search Tree(BST).

    BINARY SEARCH TREE:
        => As the name suggest, it is a binary tree, meaning, at any node at most it can have 2 children.
        => but what truly makes BST shines is that, at any given node its
            => children to the left is always smaller than that of the parent node and
            => children to the right are always bigger then that of the parent node.

                                    ----------------
                                    |  parent Node |
                                    ----------------
                                    /               \
                                   /                 \
                                Smaller             Bigger
                                

*/

#include <iostream>
#include <initializer_list>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int value): value(value), left(nullptr), right(nullptr){}
};

class BST{
    private:
        Node* root;

        Node* createNewNode(int value){
            Node* newNode = new Node(value);
            return newNode;
        }

        Node* insertNodeHelper(Node* node, int value){
            if(node == nullptr){
                return createNewNode(value);  
            }
            if(node->value < value){
                node-> right = insertNodeHelper(node->right,value);
            }
            else{
                 node-> left = insertNodeHelper(node->left,value);
            }
            return node;
        }
    public:
        BST():root(nullptr){}
        BST(int value){
            root = createNewNode(value);
        }
        BST(initializer_list<int> listOfNodes){
            for (const int&  element: listOfNodes){
                insertNode(element);
            }
        }
       void insertNode(int value){
           root =  insertNodeHelper(root,value);
       }
       
};

int main(){

    BST *tree = new BST({10,5,17,13,1,18,6});
    return 0;
}