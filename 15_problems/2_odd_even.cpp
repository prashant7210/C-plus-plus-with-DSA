#include <iostream>
#include <vector>
using namespace std;
void sort(vector <int> &v){
    int left=0 , right=v.size()-1;
    while(left<right){
        if(v[left]%2==0){
            left++;
        }
        else if(v[right]%2!=0){
            right--;
        }
        else if(v[left]%2!=0 && v[right]%2==0){
            int c = v[left];
            v[left] = v[right];
            v[right] = c;
        }
    }
}
int  main(){    
    int n; 
    cout<<"n : ";   cin>>n;
    vector <int> v(n);
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v);
    cout<<"Even left __ Odd right : ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}