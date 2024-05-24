#include <iostream>
#include <vector>
using namespace std;
int min_ele_rot(vector<int>&v){
    if(v.size()==1)  return v[0];
    int lo=0, hi=v.size()-1;
    if(v[lo]<v[hi]) return v[lo];
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(v[mid+1]<v[mid])  return v[mid+1];
        if(v[mid]<v[mid-1])  return v[mid];
        if(v[mid]>v[lo]){
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int>v = {4,5,6,7,1,2,3};
    cout<<min_ele_rot(v);
    return 0;
}