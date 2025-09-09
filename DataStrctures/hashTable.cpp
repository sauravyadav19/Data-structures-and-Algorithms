#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable{
private:
    const int BUCKET_SIZE = 7;
    //Multiple values could be hased to same index; hence we are incoporating list to accmodate them all.
    vector<list<pair<string,int>>> table;
    int hashFunction(const string &key){
        int sum = 0;
        for(char const &letter : key){
            sum += letter;
        }
        return sum % BUCKET_SIZE;
    }
public:
    HashTable(){
        table.resize(BUCKET_SIZE);
    }
    void insert(const string &key, int value){
        int index = hashFunction(key);
        table[index].push_back({key,value});

    }
    int get(const string &key){
        // we take the key  => run it through the hash function => get the index
        // this way, we avoid having to look through all the indices
        // yes we still do have to traverse through the list that is stored at that index
        // but if we have a good hashing function there would be minimal collisions (that is multple value stored at same index)
        // and hence we have to look through less and less elements at that index as the list would be small
        // here we are returning the value of that key or -1 if there is no key at all.
        const int index = hashFunction(key);
        for(pair<string,int> value : table[index]){
            if(value.first == key){
                return value.second;
            }
        }
        return -1;
    }
    void remove(const string& key){
        // find the index of the key by running it through the hashFunction
        const int index = hashFunction(key);
        // when we get the index we know that there is a list there
        // table[index] is a list
        // an list has a predicate function called remove_if 
        // here we are passing a lambda function to it; at whatever instace fo the list
        // the value return is true that instace of pair will be deleted.
        // [&] help us the capture eveything outside by referece since we need the variable "key"
        table[index].remove_if([&] (pair<string,int> &currentPair){
            return currentPair.first == key;
        });
    }
    void getEntireTable(){

        for(int i = 0;i< 7;i++){
            cout<< "Index : " << i << " ";
            // there are lot of containers in C++ and it would be hetic for us to know how to iterate 
            // through all of them, to solve this we have a iterator defined with all these containers
            // meaning they know how to move from one elemnet to another, we simply utilise this abstraction
            // we simply create a varialbe of that container's iterator type and loop through it.
            // here we have created a iterator of list<pair<string,int>> type.
            for(list<pair<string,int>>::iterator j = table[i].begin(); j != table[i].end(); j++){
                // .first contains the first value in the pair 
                // .second contains the second value in the pair
                cout<< "{" << (*j).first << ", "<< (*j).second << " }";
            }
            cout<<endl;
        }
    }


};

int main(){
     
    HashTable h1;

    // ------INSERTING VALUES -------
    h1.insert("abc", 12);
    h1.insert("abcd", 11);
    h1.insert("Saurav", 10);
    h1.insert("Shweta", 12);
    // The way our hash function is design, if two values gets same hashed index; the later
    // hashed key-value pair will overwrite the former 
    // the same way this is happenning.
    // fixing it involes creating a Linked list for every index and storing it their
    h1.insert("atewhS", 20);

    // ------- LOOKING UP VALUES ------
    cout<< "Saurav : " << h1.get("Saurav")<<endl;
    cout << "kim : "<< h1.get("kim") <<endl;
    
    //---ENTIRE HASH TABLE -----
    h1.getEntireTable();

    h1.remove("abcd");
    h1.getEntireTable();

    return 0;

}