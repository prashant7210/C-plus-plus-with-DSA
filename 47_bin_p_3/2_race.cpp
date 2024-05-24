#include <iostream>
#include <vector>
using namespace std;
int race(vector<int>&v, int s);
bool can_place(vector<int>&V, int mid, int s);
int main(){
    vector<int>v = {1,2,4,8,9};
    int s=3;
    cout<<race(v,s);
    return 0;
}

bool can_place(vector<int>&v, int mid, int s){
    int std_req=1;
    int last_std_placed=v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i]-last_std_placed>=mid){
            std_req++;
            last_std_placed = v[i];
            if(std_req==s)  return true;
        }
    }
    return false;
}

int race(vector<int>&v, int s){
    int lo=1;
    int hi=v[v.size()]-v[0];
    int ans=-1;
    while(hi>=lo){
        int mid = lo+(hi-lo)/2;
        if(can_place(v,mid,s)){
            ans=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    return ans;
}