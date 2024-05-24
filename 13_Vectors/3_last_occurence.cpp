#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int x , occurence=-1;
    cout<<"x : ";
    cin>>x;

    for(int i=0; i<v.size(); i++){
        if(v[i]==x){
            occurence = i;
        }
    }
    if(occurence==-1){
        cout<<"Not found";
    }
    else{
        cout<<"Index(last occurence) : "<<occurence;
    }
    return 0;
}