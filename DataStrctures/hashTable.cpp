#include <iostream>
#include <vector>
using namespace std;

class HashTable{
private:
    const int BUCKET_SIZE = 7;
    vector<pair<string,int>> table;
    int hashFunction(const string &key){
        int sum = 0;
        for(char const &letter : key){
            sum += letter;
        }
        cout<<sum <<endl;
        return sum % BUCKET_SIZE;
    }
public:
    HashTable(){
        table.resize(BUCKET_SIZE);
    }
    void insert(const string &key, int value){
        int index = hashFunction(key);
        table[index] = {key,value};

    }
    void get(){

        for(int i = 0;i< 7;i++){
            cout << "{" << table[i].first << ", " << table[i].second << " } ";
        }
    }


};

int main(){
     
    HashTable h1;
    h1.insert("Saurav", 10);
    h1.insert("Shweta", 12);
    h1.insert("atewhS", 20);
    h1.get();
    return 0;

}