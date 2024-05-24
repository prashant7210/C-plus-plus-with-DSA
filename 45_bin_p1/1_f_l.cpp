#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int>&v, int target){
    int lo=0, hi=v.size()-1, ans=-1;
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(v[mid]>=target){
            ans = mid;
            hi = mid-1;
        }
        else  lo = mid+1;
    }
    return ans;
}
int upper_bound(vector<int>&v, int target){
    int lo=0, hi=v.size()-1, ans=-1;
    while(hi>=lo){
        int mid = lo + (hi-lo)/2;
        if(v[mid]>target){
            ans = mid;
            hi = mid-1;
        }
        else  lo = mid+1;
    }
    return ans;
}

int main(){
    vector<int> v = {1,2,2,3,3,3,4,4,5,6,6,7,9,9,9};
    int target = 4;
    int u = upper_bound(v,target);
    int l = lower_bound(v,target);
    cout<<"["<<l<<" , "<<u-1<<"]";
    return 0;
}