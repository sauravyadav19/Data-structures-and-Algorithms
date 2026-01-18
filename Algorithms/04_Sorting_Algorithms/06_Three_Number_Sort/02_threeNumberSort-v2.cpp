// The problem remains same as 01_threeNumberSort.cpp but we want something a little more "smart" then naïve approach, although it did the job properly and gave the array in the sorted order that we wanted,there is a smater way to do it.

/*Algorithm:
    =>we start off by creating three pointers, two of them pointing to the starting index and the last one pointing to the last index of the "values" array.

            F,S                    L
            |                      |
            v                      v
            [1, 0, 0, -1, -1, 0, 1, 1]
    => these act as the boundry keepers for the three distinct values in our "order" array.
    => we start traversing the "values" array and based on the value we move them to the region they belong that is marked by these pointers.so say at any give instance our array would like something this  

                                                     last(pointing at the start of the 3rd region)
                                                                               |
           first(pointing at the border of 1st region )                        |
                            |                                                  |
                            |                                                  |
                            v                                                  v
    {--1st element region---}{--2nd element region}--{values yet to traverse--}{--3rd Element region}]
                                                     ^
                                                     |
                                                     |
                                        second(pointing at the border of 2nd element)

    
    
    
              F      S              L
              |      |              |
              |      |              |
              v      v              v
    {0,0,0,0 ,1,1,1 ,0,-1,1,-1,1,  -1,-1,-1,-1}
    --I--    --II--  --yet to--     --III--

    => we simply swap the values in the "yet to traverse region to its specified region"
    => how is this better than naive approach? we did this one pass.
                                   
    
*/


#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void threeNumberSort(vector<T>& array, vector<T>& order){
   int firstElementEndBoundary = 0;
   int secondElementEndBoundary = 0;
   int lastElementStartBoundary = array.size() - 1;

   
   while(secondElementEndBoundary <= lastElementStartBoundary){
    // Swapping if the value belongs to I region
        if(array[secondElementEndBoundary] == order[0]){
            swap(array[firstElementEndBoundary],array[secondElementEndBoundary]);
            firstElementEndBoundary++;
            secondElementEndBoundary++; 
        }
        // Swapping, if the current value belongs to III region
        else if(array[secondElementEndBoundary] == order[2]){
            swap(array[secondElementEndBoundary], array[lastElementStartBoundary]);
            lastElementStartBoundary--;
        }
        // since this is also the pointer that we are using to traverse the "unsorted" part
        // we simply increment it, as we know that if we are properly sending the current value in the its correct region Ist or IIIrd, IInd automatically gets sorted
        else{
            secondElementEndBoundary++;
        }
   }
}


int main(){

    vector<char> array = {'B','A','B','A','D','D','B','D','B'};
    vector<char> order = {'D','A','B'};

    threeNumberSort(array,order);

    for(auto & i : array){
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
}