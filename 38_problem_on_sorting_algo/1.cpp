#include <iostream>
#include <vector>
using namespace std;
void f(vector<int>&v){
    bool flag=false;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v.size()-i-1; j++){
            if(v[j+1]!=0 && v[j]==0) {
                swap(v[j+1],v[j]);
                flag=true;
            }
        }
        if(!flag)  break;
    }
}
int main(){
    vector<int>v = {2,0,4,0,5,2,0,7,0,8,0,1};
    f(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}