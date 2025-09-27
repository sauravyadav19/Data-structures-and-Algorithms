#include <iostream>
#include <climits>
using namespace std;

// Node definition
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Insert function
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

// Inorder traversal (for checking tree structure)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}
void printTree(TreeNode* root, int space = 0, int indent = 5) {
    if (!root) return;

    // Increase distance between levels
    space += indent;

    // Print right child first
    printTree(root->right, space);

    // Print current node after spaces
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->value << "\n";

    // Print left child
    printTree(root->left, space);
}


struct CloseNode{
    int node;
    int closeness;
    CloseNode(int node, int clo): node(node),closeness(clo){};

};
CloseNode& helperFunction(TreeNode *root, int target, CloseNode& n){

    if(root->left !=nullptr and root->right != nullptr){
        int rootCloseness = abs(root->value - target);
        int leftCloseness = abs(root->left->value - target);
        int rightCloseness = abs(root->right->value - target);

        if (rootCloseness < leftCloseness and rootCloseness < rightCloseness and rootCloseness < n.closeness){
            n.node = root->value;
            n.closeness = rootCloseness;
        }
        if (leftCloseness< rootCloseness and leftCloseness < rightCloseness and leftCloseness < n.closeness){
            n.node = root->left->value;
            n.closeness = leftCloseness;
        }
        if (rightCloseness < leftCloseness and rightCloseness < rootCloseness and rightCloseness < n.closeness){
            n.node = root->right->value;
            n.closeness = rightCloseness;
        }

        if(target > root->value){
            helperFunction(root->right,target,n);
        }else{
            helperFunction(root->left,target,n);

        }
        
    }

    else if (root->left != nullptr and root->right == nullptr){
        int rootCloseness = abs(root->value - target);
        int leftCloseness = abs(root->left->value - target);

        if (rootCloseness < leftCloseness  and rootCloseness < n.closeness){
            n.node = root->value;
            n.closeness = rootCloseness;
        }
        if (leftCloseness< rootCloseness  and leftCloseness < n.closeness){
            n.node = root->left->value;
            n.closeness = leftCloseness;
        }
      
        helperFunction(root->left,target,n);  
    }
    else if (root->left == nullptr and root ->right != nullptr){
        int rootCloseness = abs(root->value - target);
        int rightCloseness = abs(root->right->value - target);

        if (rootCloseness < rightCloseness and rootCloseness < n.closeness){
            n.node = root->value;
            n.closeness = rootCloseness;
        }
        if (rightCloseness < rootCloseness and rightCloseness < n.closeness){
            n.node = root->right->value;
            n.closeness = rightCloseness;
        }

        helperFunction(root->right,target,n);
    }
    else{

        return n;
    }
    return n;


}
int findClosestValueInBst(TreeNode *root, int target){

    CloseNode n = CloseNode(root->value,INT_MAX);
    helperFunction(root,target,n);
    
    return n.node;

}
int main() {
    // Build a sample BST
    TreeNode* root = nullptr;
    int values[] = {10, 5, 2, 5, 1, 15,13,22,14};
    for (int v : values) {
        root = insert(root, v);
    }
    cout << endl;
    cout<< findClosestValueInBst(root,12);
    return 0;
}