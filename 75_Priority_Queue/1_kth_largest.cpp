#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& v, int k){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<v.size(); i++){
        pq.push(v[i]);
        if(pq.size()>k)   pq.pop();
    }
    return pq.top();
}

int main(){
    vector<int> v={2,5,3,6,0,1,4};
    cout<<kthLargest(v,3);
    return 0;
}