#include <iostream>
#include <vector>
using namespace std;
void ins_sort(vector<int>&v);
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ins_sort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

void ins_sort(vector<int>&v){
    int n=v.size();
    for(int i=1; i<n; i++){
        int j=i-1, current = v[i];
        while(v[j]>current  && j>=0){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = current;
    }
}