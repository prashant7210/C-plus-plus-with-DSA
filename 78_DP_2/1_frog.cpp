#include <iostream>
#include <vector>
using namespace std;
vector<int> dp;
int minCost(vector<int>& v, int idx, int k){
    // base case
    if(idx>=v.size()-1)  return 0;
    if(dp[idx]!=-1)  return dp[idx];

    int ans=INT16_MAX;
    for(int j=1; j<=k; j++){
        if(idx+j>=v.size())  break;
        ans=min(ans,minCost(v,idx+j,k)+abs(v[idx+j]-v[idx]));
    }
    return dp[idx]=ans;
}

int minCostTabulation(vector<int>& v, int k){
    vector<int> dpt(v.size(),INT8_MAX);
    int n=v.size();
    dpt[n-1]=0;
    for(int i=n-2; i>=0; i--){
        for(int j=1; j<=k; j++){
            if(i+j>=n)  break;
            dpt[i]=min(dpt[i],dp[i+j]+abs(v[i]-v[i+j]));
        }
    }
    return dpt[0];
}

int main(){
    dp.clear();
    vector<int> v={40,10,20,70,80,10,20,70,80,60};
    dp.resize(v.size(),-1);
    cout<<minCost(v,0,4)<<endl;
    cout<<minCostTabulation(v,4)<<endl;
    return 0;
}