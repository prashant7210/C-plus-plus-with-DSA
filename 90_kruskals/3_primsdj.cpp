#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;

vector<list<pp>> graph;
void add_edges(int src, int dest, int wt, bool bi=true){
    graph[src].push_back({dest, wt});  // node, wt
    if(bi)  graph[dest].push_back({src, wt});
}

ll prims(int src, int n){
    priority_queue<pp, vector<pp>, greater<pp>> pq;  // wt, node
    unordered_set<int> visited;  // node
    unordered_map<int, int> m;  // node, wt
    vector<int> parent(n+1); // via

    for(int i=0; i<=n; i++)  m[i]=INT32_MAX;

    m[src]=0;
    pq.push({0, src});
    parent[src]=-1;

    int edge_count=0;
    ll ans=0;

    while(not pq.empty() and edge_count<n){
        pp curr =pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        edge_count++;
        visited.insert(curr.second);
        pq.pop();
        ans+=curr.first;

        for(pp neighbour:graph[curr.second]){
            if(not visited.count(neighbour.first) and m[neighbour.first]>neighbour.second){
                m[neighbour.first]=neighbour.second;
                pq.push({neighbour.second, neighbour.first});
                parent[neighbour.first]=curr.second;
            }
        }
    }
    return ans;
}

int main(){
    int n, e;
    cin>>n>>e;
    graph.resize(n+1, list<pp>());
    while(e--){
        int src, dest, wt;
        cin>>src>>dest>>wt;
        add_edges(src, dest, wt);
    }
    int src;  cin>>src;
    cout<<prims(src, n);
    return 0;
}