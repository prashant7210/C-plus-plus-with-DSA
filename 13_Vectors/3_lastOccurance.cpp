#include <iostream>
#include <vector>
using namespace std;
int  main(){
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

    for(int i=v.size()-1; i>=0; i--){
        if(v[i]==x){
            occurence = i;
            break;
        }
    }
    if(occurence==-1){
        cout<<"Not found";
    }
    else{
        cout<<"Last occurence at index = "<<occurence;
    }
    return 0;
}