#include <iostream>
#include <vector>
using namespace std;
int binary_s(vector<int>&input, int target, int lo, int hi);
int main(){
    vector<int>v = {1,5,8,20,14,17,20,34,40};
    int target = 17;
    cout<<binary_s(v,target,0,v.size()-1);
    return 0;
}

int binary_s(vector<int>&input, int target, int lo, int hi){
    if(lo>hi)  return -1;
    int mid = (lo+hi)/2;
    if(input[mid]==target)  return mid;
    if(input[mid]<target)  return binary_s(input,target,mid+1,hi);
    else return binary_s(input,target,lo,mid-1);
}