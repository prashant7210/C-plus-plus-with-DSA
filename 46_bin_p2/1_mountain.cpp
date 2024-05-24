#include <iostream>
#include <vector>
using namespace std;
int idx_max(vector<int>&v);
int main(){
    vector<int>v = {4,5,6,7,8,3,2,1};
    cout<<idx_max(v);
    return 0;
}

int idx_max(vector<int>&v){
    int lo=0, hi=v.size()-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(v[mid-1]<v[mid] && v[mid]>v[mid+1])  return mid;
        if(v[mid-1]>v[mid]) hi = mid-1;
        else lo=mid+1;
    }
    return -1;
}