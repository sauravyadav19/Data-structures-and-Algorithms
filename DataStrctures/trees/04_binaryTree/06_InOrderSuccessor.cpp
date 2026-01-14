#include "00_binaryTree.hpp"


// FIRST APPROACH :

// We use recurison to find in-order of the tree, also ​simultaneously keeping a flag (isNextNodeSucessor)
// When we find that the node that we are currently visiting is the node whose successor we are trying to find (key)
// we simply mark isNextNodeSuccessor to be true; which implies that whichever node is next is the successor
// we simply get the node's address and exit from the loop;


void inOrderSuccessorHelper(const Node<int>* node, int key, bool &isNextNodeSuccessor, const Node<int>* & successor){
    
    if(node == nullptr){
        return;
    }
    inOrderSuccessorHelper(node->left,key,isNextNodeSuccessor,successor);
    if(isNextNodeSuccessor == true){
        successor = node;
        isNextNodeSuccessor = false;
        return;
    }
    if(node->value == key){
        isNextNodeSuccessor = true;
    }
    inOrderSuccessorHelper(node->right,key,isNextNodeSuccessor,successor);
}

const Node<int>* inOrderSuccessor(const Node<int>* root, int key){
    const Node<int>* successor = nullptr;
    bool isNextNodeSuccessor = false;
    inOrderSuccessorHelper(root,key,isNextNodeSuccessor,successor);
    return successor;
}

//  SECOND APPROACH : this approach in terms of steps taken to find the successor is same; but with a slight
// variation of that structrally we are not using recursion but rather we have created a our own
// state manager (same as we did in 05_inOrderConstantSpace.cpp)

/*
const Node<int>* inOrdersuccessor(const Node<int>* rootNode,int key ){
    const Node<int>* previous = nullptr;
    const Node<int>* current = rootNode;
    bool isNextNodeSuccessor = false;
    
    while(current != nullptr){
        if(previous == current -> parent){
            if(current->left != nullptr){
                previous = current;
                current = current->left;

            }else{
                if(isNextNodeSuccessor == true){
                    return current;
                }
                if(key == current->value){
                    isNextNodeSuccessor = true;
                }
                previous = current;
                current = (current->right != nullptr)
                          ? current->right
                          : current->parent;
            }

        }
        else if (previous == current->left){
            if(isNextNodeSuccessor== true){
                return current;
            }
            if(key == current->value){
                isNextNodeSuccessor = true;
            }
            previous = current;
            current = (current->right != nullptr)
                      ? current->right      
                      : current->parent;

        }
        else{
            previous = current;
            current = current->parent;

        }
    }
    return nullptr;
}
*/

int  main(){
    BinaryTree<int> tree = {1,2,3,4,5,nullopt,nullopt,6};
    tree.printTree();

    const Node<int>* successor = inOrderSuccessor(tree.getRoot(),1);
    
    if(successor != nullptr){
        cout<< "successor is : " << successor->value<<endl;;
    }else{
        cout<< " N0 SUCCESSOR!"<<endl;;
    }

    return 0;
}