#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>v={4,2,5,8,9,0,1};
    for(int i=0; i<v.size()-1; i++){
        int max_idx = i;
        for(int j=i+1; j<v.size(); j++){
            if(v[max_idx]<v[j]) max_idx=j;
        }
        if(max_idx!=i)  swap(v[i],v[max_idx]);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[v.size()-i-1]<<" ";
    }
    return 0;
}