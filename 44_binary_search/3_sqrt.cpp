#include <iostream>
#include <vector>
using namespace std;
int root(int n);
int main(){
    int n;
    cin>>n;
    cout<<root(n);
    return 0;
}

int root(int n){
    int lo=1;
    int hi=n;
    int ans=0;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        if(mid*mid<=n){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ans;
}