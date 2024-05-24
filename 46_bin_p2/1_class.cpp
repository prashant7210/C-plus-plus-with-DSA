#include <iostream>
#include <vector>
using namespace std;
int idx_max(vector<int>&v){
    int lo=1, hi=v.size()-1;
    int ans = -1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(v[mid]>v[mid-1]){
            ans=mid;
            lo=mid+1;
        }
        else  hi=mid-1;
    }
    return ans;
}
int main(){
    vector<int>v = {4,5,6,7,8,3,2,1};
    cout<<idx_max(v);
    return 0;
}