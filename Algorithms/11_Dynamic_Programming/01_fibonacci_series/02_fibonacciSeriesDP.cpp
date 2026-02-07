#include<iostream>
#include <vector>

unsigned int long nthFibonacciNum( unsigned int long targetIndex){

    std::vector<unsigned int long> fibMemo(targetIndex + 1);
    fibMemo[0] = 0;

    if(targetIndex >= 1){
        fibMemo[1] = 1;
    }

    for(int iterator = 2; iterator < fibMemo.size(); iterator++){
        fibMemo[iterator] = fibMemo[iterator - 1] + fibMemo[iterator - 2];
    }
    return fibMemo[targetIndex];
    


}


int main(){
    unsigned int long  targetIndex;
    std::cout<< "Find the __th Fibonacci Number : ";
    std::cin>> targetIndex;

    std::cout<< "Number: " << nthFibonacciNum(targetIndex) << std:: endl;
    return 0;
}