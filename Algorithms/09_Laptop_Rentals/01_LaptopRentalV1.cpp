#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;
ostream& operator<<(ostream& ,vector<int>);
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


ostream& operator<<(ostream& stream, vector<int> vector){
    stream<< "{ ";
    for(int i = 0; i < vector.size(); i++){
        stream<< vector[i] << " ";
    }
    stream<< "}";

    return stream;
    
}

size_t MinNumberOfLaptopReq(vector<vector<int>>& times){
    sort(times.begin(), times.end(), [](vector<int> timeSlotA,vector<int> timeSlotB){
        return timeSlotA[0] < timeSlotB[0];
    });
    struct CompareTimeSlots{
        bool operator()(vector<int> timeSlotX,vector<int> TimeSlotY){
            return timeSlotX[1] < TimeSlotY[1];
        }
    };
    Heap<vector<int>, CompareTimeSlots> LaptopInUse;
    for(int slot = 0; slot < times.size(); slot++){
        if(LaptopInUse.isEmpty()){
            LaptopInUse.insert(times[slot]);
            continue;
        }
        if(LaptopInUse.peek()[1] > times[slot][0]){
            LaptopInUse.insert(times[slot]);
        }else{
            LaptopInUse.removeRoot();
            LaptopInUse.insert(times[slot]);
        }

    }
    LaptopInUse.print();
    return LaptopInUse.size();

}

int main(){

    vector<vector<int>> times = {{0,2},{1,2},{4,6},{0,4},{7,8},{9,11},{3,10}};
    int minLaptop = MinNumberOfLaptopReq(times);
    cout<< "Minimum Laptop Required: "<< minLaptop<<endl;
    return 0;

}