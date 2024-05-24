#include <iostream>
#include <vector>
using namespace std;
void merge_sort(vector<int>&v, int l, int r);
void merge(vector<int>&v, int l, int mid, int r);
int main(){
    int n;  cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    merge_sort(v,0,n-1);
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}

void merge_sort(vector<int>&v, int l, int r){
    // base case
    if(l>=r)  return;

    // recusive case
    int mid=(l+r)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    merge(v,l,mid,r);
}

void merge(vector<int>&v,int l, int mid, int r){
    int an=mid-l+1, bn=r-mid;
    int a[an], b[bn];
    for(int i=0; i<an; i++){
        a[i] = v[i+l];
    }
    for(int i=0; i<bn; i++){
        b[i] = v[mid+1+i];
    }

    int i=0, j=0, k=l;
    while(i<an && j<bn){
        if(a[i]>b[j])  v[k++] = b[j++];
        else  v[k++] = a[i++];
    }
    while(i<an){
        v[k++] = a[i++];
    }
    while(j<bn){
        v[k++] = b[j++];
    }
}