#include <bits/stdc++.h>
using namespace std;
int f(int n , int c){
    if(n==0) return 0;
    return pow((n%10),c) + f(n/10,c);
}
int main(){
    int n,count=0;
    cout<<"n : ";  cin>>n;
    int c=n , d=n;
    while(c!=0){
        c /= 10;
        count++;
    }
    if(f(n,count)==d) cout<<true;
    else cout<<false;
    return 0;
}