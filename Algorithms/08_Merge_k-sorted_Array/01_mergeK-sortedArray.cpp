#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T>
class MinHeap{
    private:
        vector<T> heap;

         void siftUp(size_t index){
            size_t parentNode = (index - 1)/2;
            while(index > 0 && heap[parentNode] > heap[index]){
                swap(heap[parentNode],heap[index]);
                index = parentNode;
                parentNode = (index - 1)/2;
            }
        } 

         void siftDown(size_t index){
            size_t leftChild = (2*index + 1);
            size_t rightChild = (2*index + 2);
            if(leftChild >= heap.size()){
                return;
            }
            size_t swapWith = rightChild < heap.size() && heap[rightChild] < heap[leftChild]
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
            for(size_t node = heap.size()/2; node-- > 0;){
                siftDown(node);
            }
        }
      
    public:
        
        MinHeap(){}
        
        MinHeap(initializer_list<T> list){
            heap.reserve(list.size());
            for(auto iterator = list.begin(); iterator < list.end(); iterator++){
                heap.push_back(*iterator);
            }
            heapify();
        }
        
       
        void insert(T newValue){
            heap.push_back(newValue);
            siftUp(heap.size() - 1);
        }


        T removeRoot(){
            if(!isEmpty()){
                swap(heap[0], heap[heap.size() - 1]);
                T removedElement = heap[heap.size() - 1];
                heap.pop_back();
                siftDown(0);
                return removedElement;
            }else{
                throw runtime_error("Removal Failed: Heap is Empty");
            }
        }


        T peek() const{
            if(isEmpty()){
                throw runtime_error("Peeking Failed: Heap is Empty");
            }else{
                return heap[0];
            }
        }


        bool isEmpty () const{
            return heap.empty();
        }


        void printHeap () const{
            cout<< endl<< "{ ";
            for(const T & i : heap){
                cout<< i << " ";
            }
            cout<< "}"<<endl;
        }
};


int main(){

    return 0;
}