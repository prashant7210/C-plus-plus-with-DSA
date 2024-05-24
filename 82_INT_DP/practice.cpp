#include <iostream>
#include <vector>
using namespace std;

int matrixMulti(vector<int>&v, int i, int j){
    if(i==j or i+1==j)  return 0;
    int ans=INT32_MAX;
    for(int k=i+1; k<j; k++){
        int cost=v[i]*v[k]*v[j]+matrixMulti(v,i,k)+matrixMulti(v,k,j);
        ans=min(ans,cost);
    }
    return ans;
}

int tabulation(vector<int>& v){
    vector<vector<int>> dp(v.size(),vector<int>(v.size(),0));
    for(int len=3; len<=v.size(); len++){
        for(int i=0; i+len-1<v.size(); i++){
            int j=i+len-1;
            dp[i][j]=INT32_MAX;
            for(int k=i+1; k<j; k++){
                dp[i][j]=min(dp[i][j],v[i]*v[k]*v[j]+dp[i][k]+dp[k][j]);
            }
        }
    }
    return dp[0][v.size()-1];
}

int main(){
    vector<int> v={40,20,30,10,30};
    cout<<matrixMulti(v,0,v.size()-1)<<endl;
    cout<<tabulation(v)<<endl;
    return 0;
}