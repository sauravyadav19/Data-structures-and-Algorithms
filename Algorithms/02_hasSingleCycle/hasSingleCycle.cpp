#include <iostream>
#include <vector>
using namespace std;

bool hasSingleCycle(vector<int>& array){
   int index = 0;
   int upperLimit = array.size();

   for(int i = 0; i < array.size(); i++){
      cout<< index<< " => ";
      index = index + array[index];
      index = (index % upperLimit + upperLimit)% upperLimit;
   }
   cout<<endl;
   if(index == 0)
      return true;
   else
      return false;
}

int main(){

    vector<int> array = {2,3,1,-4,-4,2};

    cout<<hasSingleCycle(array);
    return 0;
}
 