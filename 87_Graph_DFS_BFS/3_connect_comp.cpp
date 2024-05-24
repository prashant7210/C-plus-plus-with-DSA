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

void dfs(int src){
    visited.insert(src);
    for(int neighbour:graph[src]){
        if(not visited.count(neighbour))  dfs(neighbour);
    }
}

int connected_component(){
    int ans=0;
    visited.clear();
    for(int i=0; i<v; i++){
        if(visited.count(i)==0){
            ans++;
            dfs(i);
        }
    }
    return ans;
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

    cout<<connected_component();
    return 0;
}