#include <iostream>
using namespace std;
bool f(int n, int *a, int k, int idx){
    if(idx==n)  return false;
    return a[idx]==k || f(n,a,k,idx+1);
}
int main(){
    int n,k;
    cout<<"n : ";  cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"k : ";  cin>>k;
    cout<<f(n,arr,k,0);
    return 0;
}