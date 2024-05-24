#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n , k;
    vector <int> v = {1,2,3,4,5,6};
    cout<<"k : ";
    cin>>k;
    k %= v.size();
    reverse(v.begin(),v.end());
    reverse(v.begin(),v.begin()+k);
    reverse(v.begin()+k,v.end());
    cout<<"Rotated element : ";
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}