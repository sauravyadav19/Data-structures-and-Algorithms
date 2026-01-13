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


#include<iostream>
#include<queue>
#include<optional>
#include<vector>
using namespace std;

// Template is used to  make this program generic, so we can create binary tree of any datatype alike.

template <typename T>
struct Node{
    T value;
    Node* left;
    Node* right;
    Node* parent;
    Node(const T &value, Node* parent = nullptr):value(value), left(nullptr), right(nullptr),parent(parent){}
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
        /* what and why data strcture used here are for
            1. Initializer List: we want to give the user a simple user interface so they do not have
                care strcutring of the data; all they have to do is, specify data type of the binary tre
                they want to create the name of tree and the nodes in a list like form:
                    binaryTree<int> myTree = {1,2,3,4,5,6,7};
            2. optional: there are times that when we want to create a tree like this: 

                                    1                           => Level 1
                               /        \
                             /           \
                            /             \
                          null            3                     => Level 2
                                        /   \
                                       /     \
                                      6       7                  => Level 3
                
                as we can see that we want to left subtree of the root to be pointing to nothing (nullptr)
                and this will create a list like this {1,nullptr,3,6,7}, there is no way to store null to 
                a int type or absence of a value; 
                    int x = 5; (valid)
                    int x = null  (X not allowed)
                so to represnt a absence of value, C++ came up with optional<T>
                    optional<int> x = 5;  (allowed)
                    optional<int> x = nullopt (absence of a value is also allowed)

                x.has_value() tell whether the container has a value or not and if it has a value 
                we can access it using x.value();
                so in our program we were able to create a initializer list of optional containers for a 
                generic type so it can also hold null values something like this {1,nullopt,3,4,5,6};
            3. Queue: We are taking values from the intialzier list and then creating a node, but we need
                a systemic way to add children nodes to parents, queue help us to do exactly that by manintaing
                a the order in which the nodes should be inserted and on which side of the parent node
                

        */
        BinaryTree(initializer_list<optional<T>> list){   
            if(list.size() == 0 or !list.begin()->has_value()){
                this->root = nullptr;
                return;
            }                         
           
            // Taking first value of the list as the root node
            this->root = new Node<T> (list.begin()->value(),nullptr);  
            queue<Node<T>*> insertingOrder;
            insertingOrder.push(root);
            // an iterator to traverse the intializer list 
            const optional<T>* listIterator = list.begin() + 1;

            while(listIterator != list.end() && !insertingOrder.empty()){
                // Taking the front most value from the Queue as sotring it as node to do the processing
                // Poping the front most value from the Queue
                // taking the value from the list and adding it to the left side of the current parent node, if the container there has a value
                // and then adding this newly added child node to end of the queue
                // incrementing the list iterator
               // taking the value from the list and adding it to the right side of the current parent node, if the container there has a value
                // and then adding this newly added child node to end of the queue
                // incrementing the list iterator
                // all this is done untill either the list is empty or the queue is empty;

                // side note: it is understandable why we are checking whether the list is empty or not
                // but what about the queue, why are we checking that whether that is empty or not, to answer that
                // we need  a case, suppose we have list like this {1,nullopt,nullopt,2,3}; here even though the list has
                // more values, the queue is empty and the leftover values cannot be added, thus we need to handle this case
                // gracefully and exit without throwing error.
                Node<T>* currentParentNode = insertingOrder.front();
                insertingOrder.pop();
                // Left side
                if(listIterator != list.end()){
                    if(listIterator->has_value()){
                        currentParentNode->left = new Node<T>(listIterator->value(),currentParentNode);
                        insertingOrder.push(currentParentNode->left);
                    }
                    listIterator++;
                }

                // Right side

                if(listIterator != list.end()){
                    if(listIterator->has_value()){
                        currentParentNode->right = new Node<T>(listIterator->value(),currentParentNode);
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

// a method to print the tree for debugging purposes
template <typename T>
void BinaryTree<T>::printTreeHelper(const Node<T>* root, int space, int indent) const {
           
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

template <typename T>
void BinaryTree<T>::printTree()const{
    printTreeHelper(this->root);
}


// a method of the Binary tree class to return the depth first order of the nodes.
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



// a method of the binary tree class to return the breadth first order of the nodes.
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

// a private method that traverses the tree in level order fashion and match the value of each node against a key
// the first ocurrence of the key in the tree is returned, the address to be specific, even if there are multiple nodes of 
// same value as the key. (so only the left most node is returned)
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

// This private method is the manager of findNodeHelper(); it provides the key and when the value is returned (if any) sends 
// appropriate response
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

// This is the public method for user to find a node with a value and replace it with a new one
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

// This is a private method that inverts the tree, that is if a node is in left it goes to the right side and vice versa of its
// parent; this happens to all the nodes in the tree thus "inverting" it.
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
// This is the public function expose to the user for inverting the tree
template <typename T>
void BinaryTree<T>:: invert(){
    invertHelper(root);
}
// This is a private helper method to find the in-order of the binary tree
template <typename T>
void BinaryTree<T>::inOrderHelper(const Node<T>* node, vector<T>& inOrderArray){
    if(node == nullptr){
        return;
    }
    inOrderHelper(node->left,inOrderArray);
    inOrderArray.push_back(node->value);
    inOrderHelper(node->right,inOrderArray);
}

// This is the public function for in-order traversal
template <typename T>
vector<T> BinaryTree<T>::inOrder(){
    vector<T> inOrderArray;
    inOrderHelper(root,inOrderArray);
    return inOrderArray;
}

int main(){
   BinaryTree<int> b = {1,2,5,3,4,6,7,8,nullopt,nullopt,11,nullopt,nullopt,nullopt,9};
   const Node<int>* root = b.getRoot();

   b.printTree();
   
   vector<int> df = b.depthFirstOrder();

   vector<int> bf = b.breadthFirstOrder();

   cout<< "Depth first order: ";
   for(int&i: df){
    cout<< i << " ";
   }
   cout<<endl;

   cout<<"Breadth first order: ";
   for(int& i : bf){
    cout<< i << " ";
   }
   cout<<endl;

   int oldValue = 4;
   int newValue = -400;
   b.setValueIf(oldValue,newValue);

   b.invert();
   cout<< "---------updated tree---------"<<endl;
   b.printTree();

   cout<< "In Order traversal: ";
   for(auto & i :b.inOrder()){
        cout<< i << " ";
   }
   cout<<endl;



    return 0;
}