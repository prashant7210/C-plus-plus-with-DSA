#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int largestPoint(vector<int>v, int k){
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i:v)  pq.push(i);

    while(k--){
        int  f=pq.top();
        pq.pop();
        int s=pq.top();
        pq.pop();
        
        pq.push(f*s);
    }

    while(pq.size()>1)  pq.pop();

    return pq.top();
}

int main(){
    cout<<largestPoint({2,4,3,1,5},3);
    return 0;
}