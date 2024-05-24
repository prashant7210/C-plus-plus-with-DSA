#include <iostream>
#include <vector>
using namespace std;
int peak(vector<int>&v){
    int lo=0, hi=v.size()-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(mid==0){
            if(v[mid]>v[mid+1])  return 1;
            else return 0;
        }
        if(mid==v.size()-1){
            if(v[mid]>v[mid-1])  return v.size()-1;
            else  return v.size()-2;
        }
        if(v[mid+1]<v[mid] && v[mid]>v[mid-1])  return mid;
        if(v[mid]>v[mid+1])  hi=mid-1;
        else  lo=mid+1;
    }
    return -1;
}
int main(){
    vector<int>v = {1,2,1,2,6,5,10,3};
    cout<<peak(v);
    return 0;
}