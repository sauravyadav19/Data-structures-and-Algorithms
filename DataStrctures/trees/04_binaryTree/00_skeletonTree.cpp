#include<iostream>
#include<queue>
#include<optional>
using namespace std;

template <typename T>
struct Node{
    T value;
    Node* left;
    Node* right;
    Node(T value):value(value), left(nullptr), right(nullptr){}
};
template <typename T>
class BinaryTree{
    private:
        Node<T>* root;
    public:
        BinaryTree(Node<T>* rootNode):root(rootNode){}
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
        
       const  Node<T>* getRoot(){
            return this->root;
        }

};

template <typename T>
  void printTreeHelper(const Node<T>* root, int space = 0, int indent = 5) {
           
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
void dfs(const Node<T>* node){

    if(node == nullptr){
        return;
    }
    cout<< node->value << " ";
    dfs(node->left);
    dfs(node->right);
    
}

int main(){
    BinaryTree<int> b = {1,2,3,4,5,6,7,8,9,10};
   const Node<int>* root = b.getRoot();
   printTreeHelper(root);
   cout<< root<<endl;
   dfs(root);
    return 0;
}