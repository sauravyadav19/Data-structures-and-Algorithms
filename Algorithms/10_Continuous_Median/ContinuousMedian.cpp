#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <optional>
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


         void siftDown(size_t index,size_t endIndex){
            size_t leftChild = (2*index + 1);
            size_t rightChild = (2*index + 2);
            if(leftChild >= endIndex){
                return;
            }
            size_t swapWith = rightChild < endIndex && compare(heap[rightChild],heap[leftChild])
                            ? rightChild
                            : leftChild;
            while(leftChild < endIndex &&  compare(heap[swapWith],heap[index])){
                    swap(heap[index], heap[swapWith]);
                    index = swapWith;
                    leftChild = (2*index + 1);
                    rightChild = (2*index + 2);
                    if(leftChild >= endIndex) break;
                    swapWith = (rightChild < endIndex && compare(heap[rightChild],heap[leftChild]))
                                ? rightChild
                                : leftChild;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            } 

        }


        void heapify(){
            for (int i = (int)heap.size() / 2 - 1; i >= 0; --i) {
                siftDown(i,heap.size());
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

        Heap(const vector<T>& list){
            heap.resize(list.size());
            for(size_t i = 0; i < list.size(); i++){
                heap[i] = list[i];
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
                if(!isEmpty()){
                    siftDown(0,heap.size());
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
        vector<T> toVector(){
            return heap;
        }
};

class ContinuousMedian{
    private:
        double median;
        Heap<double, std::greater<double>> lowerHalf;
        Heap<double, std::less<double>> upperHalf;
    public:
       void balancer(){
            if (lowerHalf.size() > upperHalf.size() + 1) {
                upperHalf.insert(lowerHalf.removeRoot());
            }
            else if (upperHalf.size() > lowerHalf.size()) {
                lowerHalf.insert(upperHalf.removeRoot());
            }
        }
        void insert(double newValue){
            if(lowerHalf.isEmpty()){
                lowerHalf.insert(newValue);
                this->median = lowerHalf.peek();
                return;
            }else{
                if(newValue < lowerHalf.peek()){
                    lowerHalf.insert(newValue);
                }else{
                    upperHalf.insert(newValue);
                }
            }
            balancer();
            this->median = ((lowerHalf.size() + upperHalf.size()) % 2 == 0)
                            ?(lowerHalf.peek() + upperHalf.peek())/2
                            :(lowerHalf.peek());
        }
        optional<double> getMedian() const{
            if(upperHalf.size() == 0 && lowerHalf.size() == 0){
                return nullopt;
            }
            return median;
        }

};

int main(){
    ContinuousMedian list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    if(list.getMedian().has_value()){
        cout<< "Median: "<< list.getMedian().value();
        cout<<endl;
    }else{
        cerr<< "Empty List!"<<endl;
    }

    return 0;
}