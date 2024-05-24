#include <iostream>
#include <vector>
using namespace std;
int max_ele(vector<int>v);
void count_sort(vector<int>&v);
int main(){
    int n;  cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    count_sort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
void count_sort(vector<int>&v){
    // Finding maximum element
    int max = max_ele(v);

    // Creating frequency array
    vector<int> f(max+1,0);
    for(int i=0; i<v.size(); i++){
        f[v[i]]++;
    }

    // Calculating Cumulative frequency
    for(int i=1; i<=max; i++){
        f[i] += f[i-1];
    }

    // Calculating sorted array
    int ans[v.size()];
    for(int i=v.size()-1; i>=0; i--){
        ans[--f[v[i]]] = v[i];
    }

    // Inserting elements of ans to v
    for(int i=0; i<v.size(); i++){
        v[i] = ans[i];
    }
}

int max_ele(vector<int>v){
    int mx=v[0];
    for(int i=0; i<v.size(); i++){
        if(v[i]>mx)  mx=v[i];
    }
    return mx;
}