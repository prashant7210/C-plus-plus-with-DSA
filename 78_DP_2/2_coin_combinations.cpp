#include <iostream>
#include<vector>
using namespace std;

int coinCombination(vector<int>& coin, int x){
    int MOD=10e7;
    int n=coin.size();
    vector<int> dp(x,0);
    dp[0]=1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=x; j++){
            if(j-coin[i]<0)  continue;
            dp[j]=(dp[j]%MOD + (dp[j-coin[i]])%MOD)%MOD;
        }
    }
    return dp[x];
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0; i<n; i++)  cin>>v[i];
    cout<<coinCombination(v,x);
    return 0;
}