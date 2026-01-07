/*
    This program is meant to evaluate the expresssion that a given binary tree is representing.
    where 
        -1 denotes Addition
        -2 denotes Subtraction
        -3 denotes Division
        -4 denotes Multiplication

    for Example:    

    => input: 
                                   -1
                                /      \                      
                               /        \
                             /           \
                            /             \
                            -2            -3                  
                          /    \         /   \
                         /      \       /     \
                        /        \     /       \
                        -4       2    8         3               
                      /   \     
                     /     \ 
                    /       \ 
                    2        3     

   => output  = (((2*3)-2) + (8/3)) = 6

 */   

#include "00_binaryTree.hpp"

int expressionEvaluator(const Node<int>*);

int main(){
    BinaryTree<int> tree = {-1,-2,-3,-4,2,8,3,2,3};
    tree.printTree();
    cout<< "Result : " << expressionEvaluator(tree.getRoot()) << endl;
    return 0;
}


/*
    Algorithm:
    
    => We are recurseviely solving this program; 
    => if a node has a value of less than zero; we know that it meant to represent our arithmetic symbols,
        when we hit a node like this we look for our operand by calling the function on left side(first operand)
        and right side (second operand).
    => the base case here is when we encounter a node that has a positive value, they are meant to be use as
        operand and hence we simply return them.
    => After the recurion is done we simply return the result back to our main funcion.

*/


int expressionEvaluator(const Node<int>* node){

    if(node->value >=0){
        return node->value;
    }

    if(node->value == -1){
        return expressionEvaluator(node->left) + expressionEvaluator(node->right);
    }

    else if (node->value == -2){
        return expressionEvaluator(node->left) - expressionEvaluator(node->right);
    }

    else if (node->value == -3){
        return expressionEvaluator(node->left) / expressionEvaluator(node->right);
    }
    
    else{
        return expressionEvaluator(node->left) * expressionEvaluator(node->right);
    }


}