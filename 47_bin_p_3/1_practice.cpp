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

int total_sum(vector<int>&v){
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ans += v[i];
    }
    return ans;
}

bool can_dis(vector<int>&v, int mid, int s){
    int stdReq = 1;
    int currSum = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>mid)  return false;
        if(v[i]+currSum>mid){
            stdReq++;
            if(stdReq>s)  return false;
        }
        else currSum+=v[i];
    }
    return true;
}

int choc_dis(vector<int>&v, int s){
    int lo=v[0];
    int hi=total_sum(v);
    int ans;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(can_dis(v,mid,s)){
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ans;
}