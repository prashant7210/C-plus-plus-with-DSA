#include <iostream>
#include <vector>
using namespace std;
void f(int n,int *arr, int idx, int sum, vector<int> &result){
    if(idx==n){
        result.push_back(sum);
        return;
    }
    f(n,arr,idx+1,sum+arr[idx],result);  //picking idxth element
    f(n,arr,idx+1,sum,result);  //not picking idth element
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>result;
    f(n,arr,0,0,result);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}