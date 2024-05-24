#include <bits/stdc++.h>
using namespace std;
void zeroes_at_end(vector<int>&v){
    for(int i=v.size()-1; i>=0;  i--){
        int j=0;
        bool flag = false;
        while(i!=j){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
                flag = true;
            }
            j++;
        }
        if(!flag)  break;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    zeroes_at_end(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}