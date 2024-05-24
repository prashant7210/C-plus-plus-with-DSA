#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int>v={4,2,5,8,9,0,1};
    for(int i=0; i<v.size()-1; i++){
        int min_idx = i;
        for(int j=i+1; j<v.size(); j++){
            if(v[min_idx]>v[j]) min_idx=j;
        }
        if(min_idx!=i)  swap(v[i],v[min_idx]);
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}