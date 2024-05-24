#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v;

void addEdges(int src, int dest, bool bidirectional=true){
    graph[src].push_back(dest);
    if(bidirectional)  graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto& ele:graph[i])  cout<<ele<<" ";
        cout<<endl;
    }
}

void bfs(int src, vector<int>& dist){
    visited.clear();
    queue<int> q;
    dist.resize(v, INT16_MAX);
    dist[src]=0;

    q.push(src);
    while(not q.empty()){
        int curr=q.front();
        q.pop();
        for(int neighbour:graph[curr]){
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
}

int main(){
    int nodes, edges;   cin>>nodes>>edges;
    v=nodes;
    graph.resize(nodes, list<int>());
    while(edges--){
        int src, dest;  cin>>src>>dest;
        addEdges(src, dest);
    }
    cout<<endl;
    display();

    int s;  cin>>s;
    vector<int> dist;
    bfs(s, dist);
    for(int i=0; i<v; i++) cout<<dist[i]<<" ";
    return 0;
}