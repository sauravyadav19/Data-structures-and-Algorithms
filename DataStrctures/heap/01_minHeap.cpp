#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;


class MinHeap{
    public:
        vector<int> heap;
        MinHeap(initializer_list<int> list){
            heap.reserve(list.size());
            for(auto iterator = list.begin(); iterator < list.end(); iterator++){
                heap.push_back(*iterator);
            }
        }
        void swapValues(int& num1, int& num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        void siftUp(int index){
            
            int parentNode = (index - 1)/2;

            while(index > 0 && heap[parentNode] > heap[index]){

                swap(heap[parentNode],heap[index]);
                index = parentNode;
                parentNode = (index - 1)/2;
            }
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

    MinHeap heap = {8,12,23,17,31,30,44,102,18,9};
    heap.printHeap();
    heap.siftUp(9);
    heap.printHeap();
        


    return 0;
}