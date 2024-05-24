#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> targetSum(vector<int> &v, int target){
    vector<int> ans(2,-1);
    unordered_map<int,int> m;
    for(int i=0; i<v.size(); i++){
        int req=target-v[i];
        if(m.find(req)!=m.end()){
            ans[0]=(m[req]);
            ans[1]=i;
            return ans;
        }
        else  m[v[i]]=i;
    }
    return ans;
}

int main(){
    vector<int> v={1,4,5,11,1,16,10,2};
    vector<int> ans=targetSum(v,13);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}