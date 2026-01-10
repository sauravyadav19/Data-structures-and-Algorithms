/*
    This is a skeleton program that is meant to assist someone in creating a binary tree , all they have
    to do is give the level order traversal in a list-like form;
    {1,2,3,4,5,6,7,8,9}  will create a tree like following

                                    1                           => Level 1
                               /        \
                             /           \
                            /             \
                            2             3                     => Level 2
                          /   \         /   \
                         /     \       /     \
                        4      5      6      7                  => Level 3
                      /   \
                     /     \
                    8      9                                    => Level 4
*/ 
#pragma once 
#include<iostream>
#include<queue>
#include<optional>
#include<vector>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* left;
    Node* right;
    Node(const T &value):value(value), left(nullptr), right(nullptr){}
};
template <typename T>
class BinaryTree{
    private:
        Node<T>* root;

        void cleanUpMemory(Node<T>* node){
            if(node == nullptr){
                return;
            }
            cleanUpMemory(node->left);
            cleanUpMemory(node->right);
            delete node;
        }

        void printTreeHelper(const Node<T>*, int space = 0, int indent = 5) const;
        void depthFirstOrderHelper(const Node<T>*, vector<T>&) const;
        void breadthFirstOrderHelper(const Node<T>* ,vector<T>&) const;
        void findNodeHelper(Node<T>* node, const T& key, Node<T>* &resultNode);
        Node<T>* findNode(const T&key);
        void invertHelper(Node<T>* node);
        void inOrderHelper(const Node<T>* node, vector<T>& inOrderArray);


    public:
    
        BinaryTree(initializer_list<optional<T>> list){   
            if(list.size() == 0 or !list.begin()->has_value()){
                this->root = nullptr;
                return;
            }                         
           
            this->root = new Node<T> (list.begin()->value());  
            queue<Node<T>*> insertingOrder;
            insertingOrder.push(root);

            const optional<T>* listIterator = list.begin() + 1;

            while(listIterator != list.end() && !insertingOrder.empty()){

                Node<T>* currentParentNode = insertingOrder.front();
                insertingOrder.pop();
                if(listIterator != list.end()){
                    if(listIterator->has_value()){
                        currentParentNode->left = new Node<T>(listIterator->value());
                        insertingOrder.push(currentParentNode->left);
                    }
                    listIterator++;
                }
                if(listIterator != list.end()){
                    if(listIterator->has_value()){
                        currentParentNode->right = new Node<T>(listIterator->value());
                        insertingOrder.push(currentParentNode->right);
                    }
                    listIterator++;
                }
                    
            }      
        }

        ~BinaryTree(){
            cleanUpMemory(this->root);
            root = nullptr;
        }  
        
       const  Node<T>* getRoot() const{
            return this->root;
        }
        
        void printTree() const;
        vector<T> depthFirstOrder() const ;
        vector<T> breadthFirstOrder() const ;
        BinaryTree(const BinaryTree&) = delete;
        BinaryTree& operator=(const BinaryTree&) = delete;
        bool setValueIf( const T& oldValue,  const T& newValue);
        void invert();
        vector<T> inOrder();


};


template <typename T>
void BinaryTree<T>::printTreeHelper(const Node<T>* root, int space, int indent) const {
           
            if (root == nullptr){
                return;
            }

            space += indent;

            printTreeHelper(root->right, space);

            cout << endl;
            for (int i = indent; i < space; i++){
                cout << " ";
            }
            cout << root->value << "\n";

            printTreeHelper(root->left, space);
}

template <typename T>
void BinaryTree<T>::printTree()const{
    printTreeHelper(this->root);
}



template <typename T>
void BinaryTree<T>::depthFirstOrderHelper(const Node<T>* node, vector<T>& depthFirstOrderArray) const {
    if(node == nullptr){
        return;
    }
    depthFirstOrderArray.push_back(node->value);
    depthFirstOrderHelper(node->left,depthFirstOrderArray);
    depthFirstOrderHelper(node->right,depthFirstOrderArray); 
}

template <typename T>
vector<T> BinaryTree<T>::depthFirstOrder() const {
    vector<T> df;
    depthFirstOrderHelper(this->root,df);
    return df;
 
}


template <typename T>
void BinaryTree<T>::breadthFirstOrderHelper(const Node<T>* node, vector<T>& breadthFirstOrderArray) const {
    if(node == nullptr){
        return;
    }
    queue<const Node<T>*> order;
    order.push(node);

    while(!order.empty()){
        const Node<T>* currentNode = order.front();
        breadthFirstOrderArray.push_back(currentNode->value);
        if(currentNode->left != nullptr){
            order.push(currentNode->left);
        }
        if(currentNode->right != nullptr){ 
            order.push(currentNode->right);
        }
        order.pop();
    }
    
}

template <typename T>
vector<T> BinaryTree<T>::breadthFirstOrder() const {
    vector<T> bf;
    breadthFirstOrderHelper(this->root,bf);
    return bf;
}

template <typename T>
void BinaryTree<T>::findNodeHelper(Node<T>* node, const T& key, Node<T>* &resultNode){
    if(node == nullptr){
        return;
    }
    queue<Node<T>*> traversalQueue;
    traversalQueue.push(node);
   while(!traversalQueue.empty()){
        Node<T>* currentNode = traversalQueue.front();
        if(currentNode->value == key){
            resultNode = currentNode;
            return;
        }
        if(currentNode->left != nullptr){
            traversalQueue.push(currentNode->left);
        }
        if(currentNode->right != nullptr){
            traversalQueue.push(currentNode->right);
        }
        traversalQueue.pop();
    }
}

template <typename T>
Node<T>* BinaryTree<T>::findNode(const T& key){
    Node<T>* result = nullptr;
    findNodeHelper(root,key,result);
    if(result != nullptr){
       return result;
    }
    else{
        return nullptr;
    }
}

template <typename T>
bool BinaryTree<T>::setValueIf(const T& oldValue ,  const T& newValue){

    Node<T>* node = findNode(oldValue);

    if(node != nullptr){
        node->value = newValue;
        return true;
    }
    else{
        return false;
    }
}

template <typename T>
void BinaryTree<T>::invertHelper(Node<T>* node){
    if(node== nullptr){
        return;
    }
    Node<T>* temp = node->left;
    node->left = node->right;
    node->right = temp;
    invertHelper(node->left);
    invertHelper(node->right);

}
template <typename T>
void BinaryTree<T>:: invert(){
    invertHelper(root);
}

template <typename T>
void BinaryTree<T>::inOrderHelper(const Node<T>* node, vector<T>& inOrderArray){
    if(node == nullptr){
        return;
    }
    inOrderHelper(node->left,inOrderArray);
    inOrderArray.push_back(node->value);
    inOrderHelper(node->right,inOrderArray);
}

template <typename T>
vector<T> BinaryTree<T>::inOrder(){
    vector<T> inOrderArray;
    inOrderHelper(root,inOrderArray);
    return inOrderArray;
}