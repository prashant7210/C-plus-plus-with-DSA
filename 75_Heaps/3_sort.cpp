#include <iostream>
using namespace std;

void heapify(int arr[], int size, int curr){
    while(2*curr<=size){
        int left=2*curr;
        int right=2*curr+1;
        int mx=left;

        if(right<=size && arr[mx]<arr[right])  mx=right;

        if(arr[curr]>arr[mx])  return;
        swap(arr[curr],arr[mx]);
        curr=mx;
    }
}

void remove(int arr[], int& size){
    swap(arr[1],arr[size]);
    size--;
    heapify(arr,size,1);
}

void heapSort(int arr[], int n){   // O(nlogn)
    if(n<=1) return;

    for(int i=n/2; i>0; i--){
        heapify(arr,n,i);
    }

    while(n){
        remove(arr,n);
    }
}

int main(){
    int arr[7]={-1,5,3,2,1,4,6};
    for(int i=1; i<7; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,6);

    for(int i=1; i<7; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}