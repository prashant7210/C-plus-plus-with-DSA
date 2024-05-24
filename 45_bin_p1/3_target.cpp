#include <iostream>
#include <vector>
using namespace std;
int idx(vector<int>&v, int target);
int main(){
    vector<int>v  = {5,6,1,2,3,4};
    int target = 1;
    cout<<idx(v,target);
    return 0;
}

int idx(vector<int>&v, int target){
    int lo=0, hi=v.size()-1;
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(v[mid]==target)  return mid;
        if(v[mid]>=v[lo]){
            if(target>=v[lo] && target<v[mid])  hi = mid-1;
            else lo = mid+1;
        }
        else{
            if(target>v[mid] && target<=v[hi])  lo = mid+1;
            else hi = mid-1;
        }
    }
    return -1;
}