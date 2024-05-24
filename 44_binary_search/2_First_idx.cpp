#include <iostream>
#include <vector>
using namespace std;
int bin_s(vector<int>&input, int target);
int main(){
    vector<int>v = {1,2,2,4,4,4,7,8,8,9,9,9,10};
    int target = 9;
    cout<<bin_s(v,target);
    return 0;
}

int bin_s(vector<int>&input, int target){
    int lo=0;
    int hi=input.size()-1;
    int ans=-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(input[mid]==target){
            ans=mid;
            hi=mid-1;
        }
        else if(input[mid]>target)  hi=mid-1;
        else lo=mid+1;
    }
    return ans;
}