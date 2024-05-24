#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
int minCost(vector<int>& v, int i, int j){
    if(i==j or i+1==j)  return 0;

    if(dp[i][j]!=-1)  return dp[i][j];
    int ans=INT32_MAX;
    for(int k=i+1; k<j; k++){
        ans=min(ans,minCost(v,i,k)+minCost(v,k,j)+v[i]*v[k]*v[j]);
    }
    
    return dp[i][j]=ans;
}

int tabulation(vector<int>& v){
    dp.clear();
    dp.resize(v.size(),vector<int>(v.size(),0));

    for(int len=3; len<=v.size(); len++){
        for(int i=0; i+len-1<v.size(); i++){
            int j=i+len-1;
            dp[i][j]=INT32_MAX;
            for(int k=i+1; k<j; k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+v[i]*v[k]*v[j]);
            }
        }
    }
    
    return dp[0][v.size()-1];
}

int main(){
    vector<int> v={40,20,30,10,30};
    dp.clear();
    dp.resize(v.size(),vector<int>(v.size(),-1));
    cout<<minCost(v,0,v.size()-1)<<endl;
    cout<<tabulation(v);
    return 0;
}