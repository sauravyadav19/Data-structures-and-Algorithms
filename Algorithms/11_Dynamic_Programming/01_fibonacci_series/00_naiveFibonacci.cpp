#include<iostream>

unsigned int long nthFibonacciNum(unsigned int long targetIndex){
    if(targetIndex == 0) return 0;
    if(targetIndex == 1) return 1;

    return nthFibonacciNum(targetIndex - 1) + nthFibonacciNum(targetIndex- 2);
}

int main(){
    unsigned int long targetIndex;
    std::cout<< "Find the __th Fibonacci Number: ";
    std::cin >> targetIndex;
    std::cout<< nthFibonacciNum(targetIndex)<<std::endl;
    return 0;
}