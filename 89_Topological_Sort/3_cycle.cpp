#include <bits/stdc++.h>
using namespace std;

vector<list<int>> graph;
int v;
void add_edges(int src, int dest, bool bidirec=true){
    graph[src].push_back(dest);
    if(bidirec)  graph[dest].push_back(src);
}

bool dfs(unordered_set<int>& visited, int src, int parent){
    visited.insert(src);
    for(int neighbour:graph[src]){
        if(visited.count(neighbour) and neighbour!=parent)  return true;
        if(not visited.count(neighbour)){
            bool res=dfs(visited, neighbour, src);
            if(res)  return true;
        }
    }
    return false;
}

bool has_cycle(){
    unordered_set<int> visited;
    for(int i=0; i<v; i++){
        if(not visited.count(i)){
            if(dfs(visited, i, -1))  return true;
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