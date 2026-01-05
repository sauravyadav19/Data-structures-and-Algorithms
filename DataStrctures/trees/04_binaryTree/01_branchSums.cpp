/*
    This program is for finding out the sum of each branch of a binary tree and return that in an array

    for Example:    

    => input: 
                                    1                      
                               /        \
                             /           \
                            /             \
                            2              3                   
                          /    \         /   \
                         /      \       /     \
                        4       5      6      7                
                      /   \     /
                     /     \   /
                    8      9   10   
                    
   First Branch:  1 + 2 + 4 + 8 = 15
   Second Branch: 1 + 2 + 4 + 9 = 16
   Third Branch:  1 + 2 + 5 + 10 = 18
   Fourth Branch: 1 + 3 + 6 = 10
   Fifth Branch:  1 + 3 + 7 = 11

   => output  = [15,16,18,10,11]

 */                                           


#include "00_binaryTree.hpp"
void branchSum( const Node<int>*,vector<int>&,int sum = 0);


int main(){

    BinaryTree<int> tree = {1,2,3,4,5,6,7,8,9,10};
    tree.printTree();
    vector<int> branchSumResult;
    branchSum(tree.getRoot(), branchSumResult,0);

    cout<< endl<< "sum of Branches are : ";
    for(int &i: branchSumResult){
        cout<< i << "  ";
    }
    cout<<endl;

    return 0;
}

/*
    Algorithm:
        => we have a sum; which act as accumlator; we add the value of the node to it;
        => this is done recursively, the base case is simply when the node becomes null;
        => how do we know one branch ends and where the next one begins? 
            => we know that when both a the child nodes of a parent node is pointing to null we know that it must mean that its a leaf node and hence we simply add whatever we have so far in our sum variable as a element in the array. and move one to next branch
*/

void branchSum(const Node<int>* node, vector<int>& branchSumArray, int sum){
    if(node == nullptr){
        return;
    }
    sum = sum + node->value;
    branchSum(node->left,branchSumArray,sum);

    if(node->left == nullptr && node->right == nullptr){
        branchSumArray.push_back(sum);
    }

    branchSum(node->right,branchSumArray,sum);
}