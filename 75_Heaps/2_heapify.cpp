#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>&v, int curr){
    int size=v.size()-1;
    while(2*curr<=size){
        int left=2*curr;
        int right=2*curr+1;
        int minChild=left;

        if(right<=size && v[minChild]>v[right])  minChild=right;

        if(v[minChild]>=v[curr])  return;
        swap(v[minChild],v[curr]);

        curr=minChild;
    }
}

int main(){
    vector<int> v={-1,60,10,80,50,5,20,70};
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;

    for(int i=(v.size()-1)/2; i>0; i--){
        heapify(v,i);
    }

    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }cout<<endl;
    
    return 0;
}