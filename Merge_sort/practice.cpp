#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r);
void merge_sort(int arr[], int l, int r);
int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void merge_sort(int arr[], int l, int r){
    if(l>=r)  return;
    int mid=(l+r)/2;
    merge_sort(arr,l,mid);
    merge_sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void merge(int arr[], int l, int mid, int r){
    int an=mid-l+1, bn=r-mid;
    int a[an], b[bn];
    for(int i=0; i<an; i++){
        a[i]=arr[l+i];
    }
    for(int i=0; i<bn; i++){
        b[i]=arr[mid+i+1];
    }
    int i=0, j=0, k=l;
    while(i<an && j<bn){
        if(a[i]<b[j])  arr[k++]=a[i++];
        else arr[k++]=b[j++];
    }
    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
}