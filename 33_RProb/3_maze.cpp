#include <iostream>
using namespace std;
int f(int m, int n, int i, int j){
    if(i==m-1 and j==n-1)  return 1;
    if(i>=m || j>=n)  return 0;
    return f(m,n,i+1,j)+f(m,n,i,j+1);
}
int main(){
    int m,n;
    cin>>m>>n;
    cout<<f(m,n,0,0); 
    return 0;
}