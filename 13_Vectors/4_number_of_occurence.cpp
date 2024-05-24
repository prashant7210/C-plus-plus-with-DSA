#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n , x , occurence=0;
    cout<<"n : ";
    cin>>n;
    vector <int> v(n);
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    cout<<"x : ";
    cin>>x;
    for(int i=0; i<v.size(); i++){
        if(v[i]==x){
            occurence++;
        }
    }
    cout<<"Occurence = "<<occurence;
    return 0;
}