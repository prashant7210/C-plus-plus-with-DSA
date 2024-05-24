#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSumIsZero(vector<int> &v){
    unordered_map<int,int> m;
    int prefixSum=0;
    int maxLen=0;
    for(int i=0; i<v.size(); i++){
        prefixSum+=v[i];
        if(prefixSum==0) maxLen=i+1;
        if(m.find(prefixSum)!=m.end()){
            maxLen=max(maxLen,i-m[prefixSum]);
        }
        else m[prefixSum]=i;
    }
    return maxLen;
}

int main(){
    vector<int> v={15,-2,2,-8,1,7,10,-21,-4};
    cout<<longestSumIsZero(v);
    return 0;
}