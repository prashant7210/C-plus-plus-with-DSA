#include <iostream>
#include <vector>
using namespace std;
void sort(vector<int>&v1 , vector<int>&v2);
int main(){
    int n1,n2;
    cout<<"n1 : ";  cin>>n1;
    vector<int>v1(n1);
    cout<<"Enter first array elements : ";
    for(int i=0; i<v1.size(); i++){
        cin>>v1[i];
    }
    cout<<"n2 : ";  cin>>n2;
    vector<int>v2(n2);
    cout<<"Enter second array elements : ";
    for(int i=0; i<v2.size(); i++){
        cin>>v2[i];
    }
    sort(v1,v2);
    return 0;
}
void sort(vector<int>&v1 , vector<int>&v2){
    vector<int>v(v1.size()+v2.size());
    for(int i=0; i<v1.size(); i++){
        v[i] = v1[i];
    }
    for(int i=v1.size(); i<v.size(); i++){
        v[i] = v2[i];
    }
    
    // Sorting
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[j]<v[i])  swap(v[i] , v[j]);
        }
    }

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}