#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <list>

using namespace std;

vector<list<int>> graph;
int v;
void add_edges(int src, int dest, bool bidirec=true){
    graph[src].push_back(dest);
    if(bidirec)  graph[dest].push_back(src);
}

// Kahn's Algorithm
void topoLogicalBFS(){
    vector<int> inDegree(v, 0);
    for(int i=0; i<v; i++){
        for(int neighbour:graph[i]){
            inDegree[neighbour]++;
        }
    }
    unordered_set<int> visited;

    queue<int> qu;
    for(int i=0; i<v; i++){
        if(not inDegree[i]){
            qu.push(i);
            visited.insert(i);
        }
    }

    // BFS
    while(not qu.empty()){
        int node=qu.front();
        qu.pop();
        cout<<node<<" ";

        for(int neighbour:graph[node]){
            if(not visited.count(neighbour)){
                inDegree[neighbour]--;
                if(inDegree[neighbour]==0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
}

int main(){
    cin>>v;
    int edges;  cin>>edges;
    graph.resize(v, list<int>());
    while(edges--){
        int src, dest;
        cin>>src>>dest;
        add_edges(src, dest, false);
    }
    topoLogicalBFS();
    return 0;
}