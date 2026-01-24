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
        MinHeap(vector<T> list){
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


        void printHeap () const{
            cout<< endl<< "{ ";
            for(const T & i : heap){
                cout<< i << " ";
            }
            cout<< "}"<<endl;
        }
};

template <typename T>
struct item{
    T element;
    size_t index;
    size_t arrayPart;

    bool operator<(const item<T>& other)const{
        return element < other.element;
    }

    bool operator>(const item<T>& other) const {
        return element > other.element;
    }
    item& operator=(const item<T>& other){
        element = other.element;
        index = other.index;
        arrayPart = other.arrayPart;
        return *this;
    }
};

template <typename T>
 ostream& operator<<(ostream& stream,const item<T> it) {
        stream<< "{ " << it.element << " at "<< it.index << " of " << it.arrayPart << " }";
        return stream;
    }



template <typename T>
vector<T> minHeapManager(vector<vector<T>>& arrays){

    vector<T> finalSorted;
    vector<item<T>> smallestItems;
    for(size_t i = 0; i < arrays.size();i++){
        smallestItems.push_back({
            arrays[i][0],
            0,
            i
        } );
    }
    MinHeap<item<T>> heap = smallestItems;

    while(!heap.isEmpty()){
        item<T> PreviousTopMostElement = heap.peek();
        finalSorted.push_back(heap.removeRoot().element);
        if(PreviousTopMostElement.index + 1 < arrays[PreviousTopMostElement.arrayPart].size()){
            item<T> nextToBeInserted = {    
                arrays[PreviousTopMostElement.arrayPart][PreviousTopMostElement.index+1],
                PreviousTopMostElement.index+1,
                PreviousTopMostElement.arrayPart
            };
            heap.insert(nextToBeInserted);
        }
        heap.printHeap();
    }

    return finalSorted;


}

   


int main(){

    vector<vector<int>> arrays = {{1,5,9,21},{-1,0},{-124,81,121},{3,6,12,20,156}};
   
    vector<int> finalSorted = minHeapManager(arrays);
    cout<<endl;
    for(int & i : finalSorted){
        cout<< i<< " ";
    }
    cout<<endl;
    return 0;
}