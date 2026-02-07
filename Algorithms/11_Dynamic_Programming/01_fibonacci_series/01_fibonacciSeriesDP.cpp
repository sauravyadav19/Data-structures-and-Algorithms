#include<iostream>
#include <vector>
#include <optional>

void nthFibonacciNumHelper(unsigned int long targetIndex, std::vector<std::optional<unsigned int long>>& fibMemo){

    if(fibMemo[targetIndex].has_value())return;

    if(targetIndex == 0 ||targetIndex == 1) return;

    if(!fibMemo[targetIndex-1].has_value()){
        nthFibonacciNumHelper(targetIndex - 1,fibMemo);
    }
    if(!fibMemo[targetIndex-2].has_value()){
        nthFibonacciNumHelper(targetIndex -2,fibMemo);
    }

    fibMemo[targetIndex] = fibMemo[targetIndex - 1].value() + fibMemo[targetIndex - 2].value();
    return;
}

int long nthFibonacciNum( unsigned int long targetIndex){

    std::vector<std::optional<unsigned int long>> fibMemo(targetIndex + 1);
    fibMemo[0] = 0;

    if(targetIndex >= 1){
        fibMemo[1] = 1;
    }

    nthFibonacciNumHelper(targetIndex,fibMemo);

    return fibMemo[targetIndex].value();


}


int main(){
    unsigned int long targetIndex;
    std::cout<< "Find the __th Fibonacci Number : ";
    std::cin>> targetIndex;

    std::cout<< "Number: " << nthFibonacciNum(targetIndex) << std:: endl;
    return 0;
}