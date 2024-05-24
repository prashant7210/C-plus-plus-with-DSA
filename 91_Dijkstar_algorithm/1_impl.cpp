#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;

vector<list<pair<int, int>>> graph;  // node, wt

void add_edges(int src, int dest, int wt, bool bi=true){
    graph[src].push_back({dest, wt});
    if(bi)  graph[dest].push_back({src, wt});
}

unordered_map<int, int> dijkstras(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;  // wt, node
    unordered_set<int> visited;
    unordered_map<int, int> m;  // node, distance
    vector<int> via(n);

    for(int i=0; i<n; i++)  m[i]=INT16_MAX;

    m[src]=0;
    pq.push({0, src});

    while(not pq.empty()){
        pp curr=pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();
        
        for(pp neighbour:graph[curr.second]){
            if(not visited.count(neighbour.first) and m[neighbour.first] > m[curr.second]+neighbour.second){
                m[neighbour.first]=m[curr.second]+neighbour.second;
                via[neighbour.first]=curr.second;
                pq.push({m[neighbour.first], neighbour.first});
            }
        }
    }
    return m;
}

int main(){
    int n, e;
    cin>>n>>e;
    graph.resize(n, list<pp>());
    while(e--){
        int src, dest, wt;
        cin>>src>>dest>>wt;
        add_edges(src, dest, wt);
    }
    int src, dest;
    cin>>src>>dest;
    unordered_map<int, int> m=dijkstras(src, n);
    cout<<"Shortest distance = "<<m[dest]<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}