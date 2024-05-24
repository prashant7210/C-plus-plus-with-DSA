#include <iostream>
using namespace std;
void sort(int a[],int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int c = a[j];
                a[j] = a[i];
                a[i] = c;
            }
        }
    }
}
int main(){
    int n;
    cout<<" n : ";  cin>>n;
    int a[n];
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,n);
    cout<<"Sorted elements : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}