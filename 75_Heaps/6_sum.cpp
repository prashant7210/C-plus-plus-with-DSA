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

int remove(vector<int>& v, int k){
    int removedEle=v[1];
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    heapify(v,1);
    return removedEle;
}

int rangeSum(vector<int>& v, int k1, int k2){
    // 1.Heapify
    for(int i=(v.size()-1)/2; i>0; i--){
        heapify(v,i);
    }
    int ele=k2-k1-1;
    // 2.Remove k1 elements 
    while(k1--)  remove(v,v.size()-1);
    int s=0;
    // 3. Calculate sum by removing elements
    while(ele--){
        s+=remove(v,v.size()-1);
    }
    return s;
}

int main(){
    vector<int> v={-1,20,8,22,4,12,10,14};  // 4 8 10 12 14 20 22
    cout<<rangeSum(v,3,5);
    return 0;
}