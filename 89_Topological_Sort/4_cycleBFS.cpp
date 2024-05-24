#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void add_edges(int src, int dest, bool bidirec=true){
    graph[src].push_back(dest);
    if(bidirec)  graph[dest].push_back(src);
}

bool bfs(int src, unordered_set<int>& visited){
    vector<int> parent(v, -1);
    visited.insert(src);
    queue<int> qu;
    qu.push(src);
    while(not qu.empty()){
        int curr=qu.front();
        qu.pop();

        for(int neighbour:graph[curr]){
            if(visited.count(neighbour) and parent[curr]!=neighbour)  return true;
            if(not visited.count(neighbour)){
                parent[neighbour]=curr;
                visited.insert(neighbour);
                qu.push(neighbour);
            }
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> visited;
    for(int i=0; i<v; i++){
        if(not visited.count(i)){
            if(bfs(i, visited))  return true;
        }
    }
    return false;
}

int main(){
    int e;
    cin>>v>>e;
    graph.resize(v, list<int>());
    while(e--){
        int src, dest;
        cin>>src>>dest;
        add_edges(src, dest);
    }
    if(has_cycle())  cout<<"Cycle Detected";
    else cout<<"No cycle found";
    return 0;
}