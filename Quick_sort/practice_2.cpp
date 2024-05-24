#include <iostream>
using namespace std;
int partition(int arr[], int f, int l);
void quick_sort(int arr[], int f, int l);
int main(){
    int n;  cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n-1);
    for(int i=0;  i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void quick_sort(int arr[], int f, int l){
    // base case
    if(f>=l)  return;

    // recursive case
    int pi = partition(arr,f,l);
    quick_sort(arr,f,pi-1);
    quick_sort(arr,pi+1,l);
}

int partition(int arr[], int f, int l){
    int pivot = arr[l], i=f-1;
    for(int j=f; j<l; j++){
        if(pivot>arr[i]) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[l]);
    return i+1;
}