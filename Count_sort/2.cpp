#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void count_sort(vector<int>&v, int pos);
void radix_sort(vector<int>&v);
int main(){
    int n;  cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    radix_sort(v);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

void radix_sort(vector<int>&v){
    int mx=v[0];
    for(auto x:v){
        mx = max(x,mx);
    }
    for(int pos=1; mx/pos>0; pos*=10){
        count_sort(v,pos);
    }
}

void count_sort(vector<int>&v, int pos){
    // Creating frequency array
    vector<int>f(10,0);
    int n=v.size();
    for(int i=0; i<n; i++){
        f[(v[i]/pos)%10]++;
    }

    // CAlculating cumulativr frequency
    for(int i=1; i<10; i++){
        f[i] += f[i-1];
    }

    // sorting array on the basis of position
    vector<int>ans(n);
    for(int i=n-1; i>=0; i--){
        ans[--f[(v[i]/pos)%10]] = v[i];
    }

    // Inserting elements of ans into v
    for(int i=0; i<n; i++){
        v[i] = ans[i];
    }
}