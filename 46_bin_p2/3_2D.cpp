#include <iostream>
#include <vector>
using namespace std;
bool bin_search(vector<vector<int>>&v, int k){
    int m=v.size(), n=v[0].size();
    int lo=0, hi=(m*n)-1;
    while(hi>=lo){
        int mid=lo+(hi-lo)/2;
        int x=mid/n, y=mid%n;
        if(v[x][y]==k)  return true;
        if(v[x][y]>k)  hi=mid-1;
        else  lo=mid+1;
    }
    return false;
}
int main(){
    vector<vector<int>>v = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    int k=12;
    cout<<bin_search(v,k);
    return 0;
}