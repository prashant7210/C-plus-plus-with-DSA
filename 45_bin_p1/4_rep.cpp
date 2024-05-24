#include <iostream>
#include <vector>
using namespace std;
bool repetative_search(vector<int>&v, int target);
int main(){
    vector<int>v = {0,0,0,1,1,1,2,0,0,0};
    int target = 2;
    cout<<repetative_search(v,target);
    return 0;
}

bool repetative_search(vector<int>&v, int target){
    int lo=0, hi=v.size()-1;
    if(v[lo]==target)  return true;
    if(v[hi]==target)  return true;
    while(v[lo]==v[hi]){
            hi--;
            lo++;
        }
    while(hi>=lo){
        int mid = lo+(hi-lo)/2;
        if(v[mid]==target)  return true;
        if(v[mid]>=v[lo]){
            if(target>=v[lo] && target<v[mid])  hi=mid-1;
            else lo=mid+1;
        }
        else{
            if(target>v[mid] && target<=v[hi])  lo=mid+1;
            else hi=mid-1;
        }
    }
    return false;
}