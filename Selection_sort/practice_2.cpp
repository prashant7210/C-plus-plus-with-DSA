#include <iostream>
#include <vector>
using namespace std;
void selection_sort(vector<int>&v);
int main(){
    int n;  cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    selection_sort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

void selection_sort(vector<int>&v){
    int n = v.size();
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[min_idx])  min_idx=j;
        }
        if(i!=min_idx)  swap(v[i],v[min_idx]);
    }
}