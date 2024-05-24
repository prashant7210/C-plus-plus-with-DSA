#include <iostream>
#include <vector>
using namespace std;
int choc_dis(vector<int>&v, int s);
int total_sum(vector<int>&v);
bool can_dis(vector<int>&v, int mid, int s);
int main(){
    vector<int>v={12,34,67,90};
    int s=2;
    cout<<choc_dis(v,s);
    return 0; 
}
// ******Time Complexity = O(nlogn)******
int choc_dis(vector<int>&v, int s){
    int lo=v[0], hi=total_sum(v);
    int ans=-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(can_dis(v,mid,s)){
            ans = mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}

int total_sum(vector<int>&v){
    int ans=0;
    for(int i=0; i<v.size(); i++){
        ans+=v[i];
    }
    return ans;
}

bool can_dis(vector<int>&v, int mid, int s){
    int stdudentsReq=1;
    int curr_sum=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>mid)  return false;
        if(curr_sum+v[i]>mid){
            stdudentsReq++;
            if(stdudentsReq>s)  return false;
        }
        else{
            curr_sum+=v[i];
        }
    }
    return true;
}