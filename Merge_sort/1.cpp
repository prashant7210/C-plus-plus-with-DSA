#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&v, int l, int mid, int r){
    int an=mid-l+1;
    int bn=r-mid;
    // creating two temporary arrays
    vector<int> a(an), b(bn);
    for(int i=0; i<an; i++){
        a[i]=v[l+i];
    }
    for(int j=0; j<bn; j++){
        b[j]=v[mid+1+j];
    }

    int i=0, j=0, k=l;
    while(i<an && j<bn){
        if(a[i]>=b[j])  v[k++]=b[j++];
        else  v[k++]=a[i++];
    }

    while(i<an){
        v[k++]=a[i++];
    }
    while(j<bn){
        v[k++]=b[j++];
    }
}
void merge_sort(vector<int>&v, int l, int r){
    // base case
    if(l>=r)  return;

    int mid = (l+r)/2;
    merge_sort(v,l,mid);
    merge_sort(v,mid+1,r);
    merge(v,l,mid,r);
}
int main(){
    int n;
    cin>>n;
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