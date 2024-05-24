#include <bits/stdc++.h>
using namespace std;

class hashing{
    int buckets;
    vector<list<int>> hashTable;
    public:
    hashing(int size){
        this->buckets=size;
        this->hashTable.resize(size);
    }
    int hashValue(int key){
        return key%this->buckets;  // Division methods
    }
    void addKey(int key){
        int idx=hashValue(key);
        this->hashTable[idx].push_back(key);
    }
    list<int>::iterator searchKey(int key){
        int h=hashValue(key);
        return find(this->hashTable[h].begin(),this->hashTable[h].end(),key);
    }
    void deleteKey(int key){
        int h=hashValue(key);
        if(searchKey(key)!=hashTable[h].end()){
            this->hashTable[h].erase(searchKey(key));
        }
        else{
            cout<<"Not Present";
        }
    }
};

int main(){
    hashing h(5);
    h.addKey(1);
    h.addKey(2);
    h.addKey(3);
    h.addKey(4);
    h.addKey(5);

    h.deleteKey(6);
    return 0;
}