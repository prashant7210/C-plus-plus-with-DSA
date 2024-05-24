#include <iostream>
using namespace std;
void sort_square(int a[],int n){
    for(int i=0; i<n; i++){
        a[i] = a[i]*a[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]){
                int c = a[i];
                a[i] = a[j];
                a[j] = c;
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
    sort_square(a,n);
    cout<<"Sorted square elements : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}