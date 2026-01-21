#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;


class MinHeap{
    private:
        vector<int> heap;

         void siftUp(int index){

            int parentNode = (index - 1)/2;

            while(index > 0 && heap[parentNode] > heap[index]){

                swap(heap[parentNode],heap[index]);
                index = parentNode;
                parentNode = (index - 1)/2;
            }
        } 

         void siftDown(int index){
            int leftChild = (2*index + 1);
            int rightChild = (2*index + 2);

            if(leftChild >= heap.size()){
                return;
            }
            int swapWith = rightChild < heap.size() && heap[rightChild] < heap[leftChild]
                            ? rightChild
                            : leftChild;

            while(leftChild < heap.size() &&  heap[index] > heap[swapWith]){

                    swap(heap[index], heap[swapWith]);
                    index = swapWith;
                    leftChild = (2*index + 1);
                    rightChild = (2*index + 2);

                    if(leftChild >= heap.size()) break;

                    swapWith = (rightChild < heap.size() && heap[rightChild] < heap[leftChild])
                                ? rightChild
                                : leftChild;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            } 

        }

        void heapify(){
            for(int node = (heap.size()/2 - 1); node >= 0; node--){
                siftDown(node);
            }
        }
      
    public:
        
        MinHeap(){}
        
        MinHeap(initializer_list<int> list){
            heap.reserve(list.size());
            for(auto iterator = list.begin(); iterator < list.end(); iterator++){
                heap.push_back(*iterator);
            }
            heapify();
        }
       
        void insert(int newValue){
            heap.push_back(newValue);
            siftUp(heap.size() - 1);
        }
        void remove(){
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            siftDown(0);
        }
        int peek(){
            return heap[0];
        }
        void printHeap(){
            cout<<endl;
            for(auto & i : heap){
                cout<< i << " ";
            }
            cout<<endl;
        }
};

int main(){

    MinHeap heap = {9, 4, 7, 1, 3, 6, 5};
    heap.printHeap();
    heap.insert(0);
    heap.printHeap();
    heap.remove();
    heap.printHeap();
    cout<< "peek: "<<heap.peek()<<endl;

    return 0;
}