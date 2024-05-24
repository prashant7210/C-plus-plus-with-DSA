#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main(){
    vector<int> v={1,1,1,3,5,6,5,4,4};
    map<int,int> m;
    // storing frequency of elements
    for(int i=0; i<v.size(); i++){
        m[v[i]]++;  // Same key ocuurence -> increase the key value 
    }

    int s=0;
    for(auto ele:m){
        if(ele.second>1){
            s+=ele.first;
        }
    }
    cout<<s;
    return 0;
}