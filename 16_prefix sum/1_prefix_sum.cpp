#include <iostream>
#include <vector>
using namespace std;
void prefix_sum(vector <int> &v){
    for(int i=1; i<v.size(); i++){
        v[i] += v[i-1];
    }
}
int main(){
    vector <int> v;
    int n;
    cout<<"n : ";  cin>>n;
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    prefix_sum(v);
    cout<<"Pefix sum : ";
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}