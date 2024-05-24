#include <iostream>
#include <vector>
#include <queue>
#include<unordered_map>
using namespace std;

int leastInterval(vector<char>& v, int n){
    if(n==0)  return v.size();

    // Number of elements
    unordered_map<char,int> m;
    for(int i=0; i<v.size(); i++)  m[v[i]]++;

    // Frequency of elements
    priority_queue<int> pq;
    for(auto i:m)  pq.push(i.second);

    // Calculating time
    int time=0;
    while(not pq.empty()){
        vector<int> temp;
        for(int i=0; i<=n; i++){
            if(!pq.empty()){
                int freq=pq.top();
                pq.pop();

                if(freq>1)  temp.push_back(freq-1);
            }
            time++;
            if(pq.empty() && temp.empty())  return time;
        }
        
        for(int itr:temp)  pq.push(itr);
    }

    return time;

}

int main(){
    vector<char> v={'A','A','A','A','B','B','B'};
    cout<<leastInterval(v,2);
    return 0;
}