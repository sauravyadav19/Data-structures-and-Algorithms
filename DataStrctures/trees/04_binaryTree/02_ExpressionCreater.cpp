/*
    This program is meant to create the expresssion that a given binary tree is representing

    for Example:    

    => input: 
                                   '+'
                                /      \                      
                               /        \
                             /           \
                            /             \
                           '-'             '/'                   
                          /    \         /   \
                         /      \       /     \
                        /        \     /       \
                        '*'     '2'    '8'    '3'               
                      /   \     
                     /     \ 
                    /       \ 
                    '2'    '3'     

   => output  = (((2*3)-2) + (8/3))

 */         

#include "00_binaryTree.hpp"

void expressionCreater(const Node<char>*);

int main(){
    BinaryTree<char> tree = {'+', '-', '/', '*', '2', '8', '3', '2', '3'};
    tree.printTree();
    expressionCreater(tree.getRoot());
    return 0;
}

/*
    Algorithm:
    => we are doing this recurersively; we are traversing one node at time;
    => each time, we are evaluating whether its a arithmetic sign (+,-,*,/) or a number;
    => if its a number we are simplying printing the number;
    => but if its a symbol we are calling for the left and right operands recurersively and printing
        appropriate brackets and symbols.
    => as usual the base case for this would be when the node becomes null;
*/
void expressionCreater(const Node<char>* node){
    if(node == nullptr){
        return;
    }
    if(node->value == '+'){
        cout<< "("; expressionCreater(node->left);cout<< " + " ;expressionCreater(node->right);cout<< " )"; 
        return;
    }
    else if(node->value == '-'){
        cout<< "("; expressionCreater(node->left);cout<< " - " ;expressionCreater(node->right);cout<< " )"; 
        return;
    }
    else if(node->value == '/'){
        cout<< "("; expressionCreater(node->left);cout<< " / " ;expressionCreater(node->right);cout<< " )"; 
        return;
    }
    else if(node->value == '*'){
        cout<< "("; expressionCreater(node->left);cout<< " * " ;expressionCreater(node->right);cout<< " )"; 
        return;
    }
    else{
        cout<< node->value;
        return;
    }

}