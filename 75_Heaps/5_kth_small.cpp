#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& v, int curr){
    int size=v.size()-1;
    while(2*curr<=size){
        int left=2*curr;
        int right=2*curr+1;
        int mn=left;
        if(right<=size && v[right]<v[mn])  mn=right;
        if(v[curr]<v[mn])  return;
        swap(v[curr],v[mn]);
        curr=mn;
    }
}

void remove(vector<int>& v, int k){
    while(--k){
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        heapify(v,1);
    }
}

int main(){
    vector<int> v={-1,4,6,2,5,10};
    for(int i=(v.size()-1)/2; i>0; i--){
        heapify(v,i);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    remove(v,3);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}