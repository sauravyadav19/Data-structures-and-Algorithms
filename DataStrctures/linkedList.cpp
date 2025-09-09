#include <iostream>

struct Node{
    int data;
    Node* nextPointer;
    Node(int val) data(val) nextPointer(nullptr) {}
}

class LinkedList {
private:
    Node* head;
public:
    LinkedList()head(nullptr){}

};
int main(){
    return 0;
}