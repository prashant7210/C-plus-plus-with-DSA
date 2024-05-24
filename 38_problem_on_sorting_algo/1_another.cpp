#include <iostream>
#include <vector>
using namespace std;
void f(vector<int>&v){
    for(int i=v.size()-1; i>=0; i--){
        int j=0;
        bool flag=false;
        while(j!=i){
            if(v[j+1]!=0 && v[j]==0){
                swap(v[j+1],v[j]);
                flag = true;
            }
            j++;
        }
        if(!flag)  break;
    }
    return;
}
int main(){
    vector<int>v = {2,0,3,0,1,0,6,0,9,0,4};
    f(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}