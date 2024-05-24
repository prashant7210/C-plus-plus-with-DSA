#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"n : ";
    cin>>n;
    vector <int> v(n);
    cout<<"Enter elements : ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int even=v[0] , odd=v[1];
    for(int i=2; i<v.size(); i++){
        if(i%2==0){
            even += v[i];
        }
        else{
            odd += v[i];
        }
    }
    if(odd-even>0){
        cout<<"Ans = "<<(odd-even);
    }
    else{
        cout<<"Ans = "<<(even-odd);
    }
    return 0;
}