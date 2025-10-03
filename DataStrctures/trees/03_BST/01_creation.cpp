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

       void printTreeHelper(Node* root, int space = 0, int indent = 5) {
           
            if (root == nullptr){
                return;
            }

            // Increase distance between levels
            space += indent;

            // Print right child first
            printTreeHelper(root->right, space);

            // Print current node after spaces
            cout << endl;
            for (int i = indent; i < space; i++){
                cout << " ";
            }
            cout << root->value << "\n";

            // Print left child
            printTreeHelper(root->left, space);
        }

        void printTree(){
            printTreeHelper(root);
        }

        bool containsHelper(Node* node, int target){
            if(node == nullptr){
                return false;
            }
            if(node->value == target){
                return true;
            }
            if(target > node->value){
                return containsHelper(node->right,target);
            }
            else{
              return containsHelper(node->left,target);
            }
        }
        bool contains(int target){
            return containsHelper(root,target);
        }

       Node* leftMostValue(Node* node){

        if(node->left ==  nullptr){
            return node;
        }
        return leftMostValue(node->left);

       }
       Node* leftMostValueHelper(){
            return leftMostValue(root);
       }

       Node* searchNode(Node* node, int target){
            if(node == nullptr){
                return nullptr;
            }
            if(node->value == target){
                return node;
            }
            if(target > node->value){
                return searchNode(node->right,target);

            }else{
                return searchNode(node->left, target);
            }
       }

       Node* searchNodeHelper(int target){
        return searchNode(root,target);
       }

       void deleteElementHelper(Node* node, int target){
            if(node == nullptr){
                return;
            }
            Node* toBeDeleted = searchNode(root,target);
            Node* toBeReplacedWith = leftMostValue(toBeDeleted->right);
            toBeDeleted->value = toBeReplacedWith->value;
            Node* toBeReplacedWithParent = toBeDeleted;    
            while(toBeReplacedWithParent != nullptr){
                if(toBeReplacedWithParent-> right == toBeReplacedWith){
                    toBeReplacedWithParent->right = nullptr;
                    break;
                }
                if(toBeReplacedWithParent ->left == toBeReplacedWith){
                    toBeReplacedWithParent->left = nullptr;
                    break;
                }
                if(toBeReplacedWithParent->value > toBeReplacedWith->value){
                    toBeReplacedWithParent = toBeReplacedWithParent->left;
                }else{
                    toBeReplacedWithParent = toBeReplacedWithParent->right;

                }
            }
       }

       void deleteElement(int target){
        deleteElementHelper(root,target);
       }
};

int main(){

    BST *tree = new BST({10,5,17,1,18,6,15});
    // cout<<boolalpha;
    // cout<< tree->contains(1)<<endl;
    tree->printTree();

    cout<<endl;
    cout<<endl;
    cout<< "-------------------------------------------------------"<<endl;
    tree->deleteElement(18);
    tree->printTree();
    return 0;
}