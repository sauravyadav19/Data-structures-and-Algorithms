#include "00_binaryTree.hpp"
// In the previous approach (04_inOrderTraversal.cppp) we did managae to find the in order traversal
// without having to relay on the recursion approach and rather used stack to simulate that for us, where
// we managed all the state and order.
// But techincally it is still not an improvement, if compare it with the recursion approach which
// create a callstack for everycall, we did used an auxillary data strcture which take about O(h), h
// being the height.

// But in this approach we are using a constant O(1) space to find our in-order but there is hidden nuiance
// that now we have altered the node represenation so that each node also contains an addtional "parent" field 
// thus making it bidrectional,but this is a good trade off as itmakes a lot of things easier including this in-order traversal.

/* Algorithm:
    * In-Order consist of [Left - Root - Right]

    => if we observe carefully we only have to keep track of the following three things really to do this:
        1. If we are coming down from parent to child 
        2. if we are coming up from the left side
        3. if we are coming up from the right side
    => these states alone tell us how to manage and whats the state
    => and they barely take any space while doing so thus helping us to optimize our approach

*/
void constantSpaceInOrder(const Node<int>* node){
    const Node<int>* previous = nullptr;
    const Node<int>* current = node;
    
    while(current != nullptr){

        //Case 1: If we are going from parent to child:

        // if there is a left child to the parent keep going left
        if(previous == current->parent){
            if(current->left != nullptr){
                // the current node becomes the parent (previous) and the current's left child becomes the new current node (current) 
                previous = current;
                current = current->left;
            }else{
                // If the node we encounter has no children to its left
                // We simply print its value or do the processing as required
                cout<< current->value<< " ";
                // the "current" node becomes the "previous" and if there is a right child it becomes
                // the new "current", but in case there is no right node; the "current" is the current's parent
                previous = current;
                current = (current->right != nullptr)
                            ? (current->right)
                            : (current->parent);
            }

        }
        // CASE 2: we are coming from completing the left side of a tree to the root:
        // that means we are done wit left part and now we are at root;
        // and we know that in in-order the left node goes first and then root and then the right
        //  so we just came from finishing the left side of the root node; so now its the turn of root
        else if (previous == current->left){
            // we simply print the value or do the processing of the node
            cout<< current->value << " ";
            // the current node becomes the "previous" and the if there is a right child it becomes
            // the new "current" but in case there is no right child the new "current" is the current's parent node
            previous = current;
            current = (current ->right !=nullptr)
                      ?(current->right)
                      :(current->parent);


        }
        // Previous == current->right;
        // CASE 3: if we are coming from the right side to the root node:
        // since we are coming from the right side and its the last part in the in-order (left- root - right)
        // we do not really need do anything as all nodes are processed by then we simpoy just update the "previous" to the current and new "current"
        // to be the current's parent; thus giving the control from this subtree to the upper subtree.
        else{
            previous = current;
            current = current->parent;
        }
    }
}

int main(){

    BinaryTree<int> tree = {1,2,3,4,5,6,7,8,9,10,11};
    cout<< "in-order traversal: ";
    constantSpaceInOrder(tree.getRoot());
    cout<<endl;
    return 0;
    
}