#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n , count;
    cout<<"n : ";
    cin>>n;
    vector <int> v(n);
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    bool sorted=true;
    for(int i=1; i<v.size(); i++){
        if(v[i]<=v[i-1]){
            sorted = false;
        }
    }
    if(sorted==1){
        cout<<"Sorted";
    }
    else{
        cout<<"Not sorted";
    }
    return 0;
}