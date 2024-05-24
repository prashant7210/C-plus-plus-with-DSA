#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

vector<list<int>> graph;

void addEdges(int& src, int& dest, bool undirected=true){
    graph[src].push_back(dest);
    if(undirected)  graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto& ele:graph[i])  cout<<ele<<" ";
        cout<<endl;
    }
}

unordered_set<int> visited;
bool pathExist(int src, int dest){
    if(src==dest)  return true;

    visited.insert(src);
    for(auto neighbour:graph[src]){
        if(visited.find(neighbour)==visited.end()){
            bool res=pathExist(neighbour, dest);
            if(res)  return true;
        }
    }
    return false;
}

void allPaths(int src, int dest, vector<int>& path, vector<vector<int>>& ans){
    if(src==dest){
        path.push_back(src);
        ans.push_back(path);
        path.pop_back();
        return;
    }

    visited.insert(src);
    path.push_back(src);
    for(auto neighbour:graph[src]){
        if(not visited.count(neighbour))  allPaths(neighbour, dest, path, ans);
    }
    path.pop_back();
    visited.erase(src);
}

int main(){
    int nodes;  cin>>nodes;
    int edges;  cin>>edges;
    graph.clear();
    graph.resize(nodes, list<int>());
    while(edges--){
        int src, dest;
        cin>>src>>dest;
        addEdges(src,dest);
    }
    visited.clear();
    cout<<endl;
    display();
    cout<<endl;
    int s,d;
    cin>>s>>d;
    if(pathExist(s,d))  cout<<"Yes";
    else  cout<<"No";

    vector<int> path;
    vector<vector<int>> ans;
    allPaths(s,d,path,ans);
    // for(int i=0; i<ans.size(); i++){
    //     for(int j=0; j<ans[i].size(); j++)  cout<<ans[i][j]<<" ";
    //     cout<<endl;
    // }
    return 0;
}