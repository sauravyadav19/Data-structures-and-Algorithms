#include "00_binaryTree.hpp"
#include<stack>

// This is an iterative approach for finding the in-order of a binary tree, finding the in-order of a binary tree
// using recursion is much easier and can be done with very few lines of code than iterative approach; The goal of this
// program is to build the understanding of things are handle and done during recursion and understand the nuances that 
// gets abstracted by it


/*  
    ALGORITHM:
    1. we create a stack that keeps track of in which order we should move about (simulate the recursion callback)
    2. we start off my going the the lefmost node in the tree and working our way back up.
    3. when we get to the leftmost node in the binary tree, we work our way up.
    4. stack keeps the track of order that we should be moving; we simply look for the top most value in the stack
    5. we start of by finding if there are subtrees to our nodes's parent, if yes we repeat starting from step 2 for that subtree.
    6. this is done until the stack is empty
*/
void iterativeInOrder(const Node<int>* node){
    // A Stack to keep track of where we are, where we came from and where to go next.
    stack<const Node<int>*>s;

    // we know that in-order starts with the leftmost node of the tree
    while(node != nullptr){
        // we simply push the nodes from root to all the nodes that are in the left until we reach the leftmost last node
        s.push(node);
        node = node->left;
    }
    // now coming out of that loop we know we are at the leftmost node in the tree.
    // and stack consist of the leftnodes starting from the root node to this node.
    while(!s.empty()){
        // take the top most value of the stack
       const Node<int>* curr = s.top();
       // print it 
       cout<< curr->value<<" ";
       // and then pop it
       s.pop();
       // if there is a right side to the parent node
       if(curr->right != nullptr){
        // it becomes a subtree of its own and then we repeat the whole process 
        // as if the subtree is just another tree and the node being the root
        // we simply traverse to the leftmost node of this subtree and work are way up from there
        const Node<int>* subTree =curr->right;
        while(subTree != nullptr){
            s.push(subTree);
            subTree = subTree->left;
        }
       }
       // This goes on until we have emptied the list.

    }
}

int main(){
    BinaryTree<int> tree = {1,2,3,4,5,6,7,8,9,10,11};
    tree.printTree();
    cout<<"In-Order of the tree is : ";
    iterativeInOrder(tree.getRoot());
    cout<<endl;
    return 0;
}