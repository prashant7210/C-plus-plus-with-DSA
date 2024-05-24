#include <iostream>
using namespace std;
int partition(int arr[], int l, int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l; j<r; j++){
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quick_sort(int arr[], int l, int r){
    if(l>=r)  return;
    int pi=partition(arr,l,r);
    quick_sort(arr,l,pi-1);
    quick_sort(arr,pi+1,r);
}
int main(){
    int n;  cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}