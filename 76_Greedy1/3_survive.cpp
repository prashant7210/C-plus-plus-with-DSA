#include <bits/stdc++.h>
using namespace std;
int canSurvive(int& s, int& m, int& n){
    double food=(s-s/7)*n;
    double req=s*m;
    if(food<req)  return -1;
    else if(food==req)  return (s*m)/n;
    return floor((s*m)/n)+1;
}
int main(){
    int s=10,m=2,n=22;
    cout<<canSurvive(s,m,n);
    return 0;
}