#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y){
    return x>y;
}

int minCost(int n, int m, vector<int> &X, vector<int>& Y){
    sort(X.begin(),X.end(),cmp);
    sort(Y.begin(),Y.end(),cmp);
    int h=0,v=0;
    int hr=1,vr=1;
    int ans=0;
    while(h<Y.size() && v<X.size()){
        if(X[v]>Y[h]){
            ans+=vr*X[v];
            hr++;

            v++;
        }
        else{
            ans+=hr*Y[h];
            vr++;

            h++;
        }
    }
    while(h<Y.size()){
        ans+=hr*Y[h];
        vr++;

        h++;
    }
    while(v<X.size()){
        ans+=vr*X[v];
        hr++;

        v++;
    }
    return ans;
}

int main(){
    vector<int> X={2,1,3,1,4};
    vector<int> Y={4,1,2};
    cout<<minCost(4,6,X,Y);
    return 0;
}