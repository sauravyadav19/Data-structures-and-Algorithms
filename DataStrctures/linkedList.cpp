#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* nextPointer;
    Node(int value): data(value), nextPointer(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr){}
    
    void insertAtBeg(int value){
        // this will return a Node wherein we are instering the value using Node's constrcutor
        Node *newNode = new Node(value);
        // we are then making it nextPointer point to whatever "head" is pointing to 
        newNode->nextPointer = head;
        // now we update the head to point the our new node and hence inserting it at the begining
        head = newNode;

        // Example: 
                //---Before----
                // head -> [ 10 | 0xhghg] -> [ 20 | 0xhfedcem] -> [ 30 | nullptr]

                // new Node
                // [49 | nullptr]

                // --After---
                //  head => [49 | oldHeadPonint i.e where 10 is stored] => [ 10 | 0xhghg] -> [ 20 | 0xhfedcem] -> [ 30 | nullptr]
    }

    void insertAtEnd(int value){
        Node *newNode = new Node(value);
        if(head == nullptr){
            head = newNode;
            return;
        }
        else{
            //traversing until we found the node whose next pointer is null
            // then instead of storing null there we put the address of our newly created node
            // and thus inserting it at the end; 
            Node *traverseNode = head;
            while(traverseNode->nextPointer !=nullptr){
                traverseNode = traverseNode->nextPointer;
            }
            traverseNode->nextPointer = newNode;
        }
    }

    bool searching(int key){
        bool found = false;
        if(head == nullptr){
            cout<< "List is empty"<<endl;
            return found;
        }
        Node *traverseNode = head;
        while(traverseNode !=nullptr){
            if(traverseNode->data == key){
                found = true;
                return found;
            }
            traverseNode = traverseNode ->nextPointer;
        }
        return found;
    }

    void display(){
        if(head == nullptr){
            cout<< "List is Empty"<<endl;
            return;
        }
        Node *traverseNode = head;
        while(traverseNode != nullptr){
            cout << "[ " << traverseNode->data << " | " << traverseNode->nextPointer << " ] -> ";
            traverseNode = traverseNode->nextPointer;
        }
        cout << "NULL" <<endl;
    }

};
int main(){

    LinkedList l = LinkedList();
    l.insertAtEnd(10);
    l.insertAtBeg(20);
    l.insertAtEnd(30);
    l.display();

    cout<< "Searching for 20: " << (l.searching(20) ? "Found" : "Not Found")<<endl ;
    cout<< "Searching for 40: " << (l.searching(40) ? "Found" : "Not Found")<<endl ;
    return 0;
}