#include <iostream>
#include <vector>
using namespace std;
int sort(vector<int>&v){
    int left_ptr = 0 , right_ptr = v.size()-1;
    while(left_ptr<right_ptr){
        if(v[left_ptr]==1 && v[right_ptr]==0){
            v[left_ptr++] = 0;
            v[right_ptr--] = 1;
        }
        else if(v[left_ptr]==0){
            left_ptr++;
        }
        else if(v[right_ptr]==1){
            right_ptr--;
        }
    }
}
int main(){
    int n; 
    cout<<"n : ";   cin>>n;
    vector <int> v(n);
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v);
    cout<<"Sorted elements : ";
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}