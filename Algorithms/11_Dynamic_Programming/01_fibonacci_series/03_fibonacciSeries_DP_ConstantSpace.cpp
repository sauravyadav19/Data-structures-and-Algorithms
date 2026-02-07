#include<iostream>
#include <vector>


unsigned int long nthFibonacciNum( unsigned int long targetIndex){

    if(targetIndex <= 1) return targetIndex;

    unsigned int long prevPrevious = 0;
    unsigned int long previous = 1;
    unsigned int long current = 1;

    for(unsigned int long iterator = 2; iterator <= targetIndex; iterator++){
        current = previous + prevPrevious;
        prevPrevious = previous;
        previous = current;
    }
    return current;
    
}


int main(){
    unsigned int long  targetIndex;
    std::cout<< "Find the __th Fibonacci Number : ";
    std::cin>> targetIndex;

    std::cout<< "Number: " << nthFibonacciNum(targetIndex) << std:: endl;
    return 0;
}