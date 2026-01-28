#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

template <typename T, typename Compare = std::less<T>>
class Heap{
    private:
        vector<T> heap;
        Compare compare;

         void siftUp(size_t index){
            size_t parentNode = (index - 1)/2;
            while(index > 0 && compare(heap[index],heap[parentNode])){
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
            size_t swapWith = rightChild < heap.size() && compare(heap[rightChild],heap[leftChild])
                            ? rightChild
                            : leftChild;
            while(leftChild < heap.size() &&  compare(heap[swapWith],heap[index])){
                    swap(heap[index], heap[swapWith]);
                    index = swapWith;
                    leftChild = (2*index + 1);
                    rightChild = (2*index + 2);
                    if(leftChild >= heap.size()) break;
                    swapWith = (rightChild < heap.size() && compare(heap[rightChild],heap[leftChild]))
                                ? rightChild
                                : leftChild;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            } 

        }


        void heapify(){
            for (int i = (int)heap.size() / 2 - 1; i >= 0; --i) {
                siftDown(i);
            }
        }
      
   
    public:
        
        Heap(){}
        
        Heap(initializer_list<T> list){
            heap.reserve(list.size());
            for(auto iterator = list.begin(); iterator < list.end(); iterator++){
                heap.push_back(*iterator);
            }
            heapify();
        }


        explicit Heap(vector<T>&& list) : heap(std::move(list)) {
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
                if(!isEmpty()){
                    siftDown(0);
                }
                return removedElement;
            }else{
                throw runtime_error("Removal Failed: Heap is Empty");
            }
        }


       const T& peek() const{
            if(isEmpty()){
                throw runtime_error("Peeking Failed: Heap is Empty");
            }else{
                return heap[0];
            }
        }


        bool isEmpty () const{
            return heap.empty();
        }


       void print() const{
            cout << "{ ";
            for (const T& i : heap) {
                cout << i << " ";
            }
            cout << "}"<<endl;
        }


        size_t size() const {
            return heap.size();
        }

};

vector<int> sortKSortedArray(vector<int>& array, int k){

    vector<int> sortedArray;
    Heap<int> minHeap;

    int iterator = 0;

    for(; iterator < array.size()&& iterator<=k; iterator++){
        minHeap.insert(array[iterator]);

    }
    while(iterator < array.size()){
        sortedArray.push_back(minHeap.removeRoot());
        minHeap.insert(array[iterator]);
        iterator++;
    }

    while(!minHeap.isEmpty()){
        sortedArray.push_back(minHeap.removeRoot());
    }
    return sortedArray;
}



int main(){
    vector<int> array {3, 2, 6, 5, 4, 8};
    int k = 2;
    vector<int> sortedArray = sortKSortedArray(array,k);

    cout<<"{ ";
    for(int& element : sortedArray){
        cout<< element << " ";
    }
    cout<<"} "<<endl;
    return 0;
}

