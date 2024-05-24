#include <iostream>
#include <vector>
using namespace std;
int max_ele(vector<int>v);
vector<int> f_cf_array(vector<int>v);
vector<int> cumulative_freq(vector<int>v);
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

int max_ele(vector<int>v){
    int mx=v[0];
    for(int i=0; i<v.size(); i++){
        if(v[i]>mx)  mx=v[i];
    }
    return mx;
}

vector<int> f_cf_array(vector<int>v){
    vector<int>f(max_ele(v)+1,0);
    for(int i=0; i<v.size(); i++){
        f[v[i]]++;
    }

    for(int i=1; i<=max_ele(v); i++){
        f[i] += f[i-1];
    }
    return f;
}

void count_sort(vector<int>&v){
    vector<int>p(max_ele(v)+1);
    p = f_cf_array(v);
    int ans[v.size()];
    for(int i=0; i<v.size(); i++){
        ans[--p[v[i]]] = v[i];
    }
    for(int i=0; i<v.size(); i++){
        v[i] = ans[i];
    }
}