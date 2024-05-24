#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;

int f_MemoIzition(int n){
    if(n==0 || n==1)  return n;
    if(dp[n]!=-1)  return dp[n];

    return dp[n]=f_MemoIzition(n-1)+f_MemoIzition(n-2);
}

int f_Tabulation(int n){
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int main(){
    int n;
    cout<<"n : ";  cin>>n;
    dp.resize(n+1,-1);
    cout<<f_MemoIzition(n)<<endl;
    cout<<f_Tabulation(n)<<endl;
    return 0;
}