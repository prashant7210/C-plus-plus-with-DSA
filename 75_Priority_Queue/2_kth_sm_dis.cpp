#include <iostream>
#include <vector>
#include<queue>
using namespace std;

vector<pair<int,int>> kthClosestPoints(vector<pair<int,int>>& pts, int k){
    priority_queue<pair<int,pair<int,int>>> pq;
    for(auto &pt:pts){
        int distance=pt.first+pt.second;
        pq.push(make_pair(distance,pt));

        if(pq.size()>k)  pq.pop();
    }

    vector<pair<int,int>> ans(k);
    while(not pq.empty()){
        ans[pq.size()-1]=pq.top().second;
        pq.pop();
    }
    return ans;
}

int main(){
    vector<pair<int,int>> v;
    v={make_pair(5,3),make_pair(1,2),make_pair(3,4),make_pair(5,6),make_pair(7,8),make_pair(9,10)};
    v=kthClosestPoints(v,3);
    for(auto p:v){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}