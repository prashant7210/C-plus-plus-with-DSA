#include <bits/stdc++.h>
using namespace std;
int f(int n, int h[], int idx){
    if(idx==n-1)  return 0;
    else if(idx==n-2)  return (abs(h[idx+1]-h[idx]) + f(n, h,idx+1));
    return min((f(n,h,idx+1) + abs(h[idx]-h[idx+1])),(f(n,h,idx+2) + abs(h[idx]-h[idx+2])));
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    int a[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<"Minimum cost = "<<f(n,a,0);
    return 0;
}