#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

vector<unordered_map<int,int>> graph;

void addEdges(int src, int dest, int wt, bool biDirec=true){
    graph[src][dest]=wt;
    if(biDirec)  graph[dest][src]=wt;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<") ";
        }
        cout<<endl;
    }
}

int main(){
    int v;  cin>>v;
    graph.resize(v,unordered_map<int,int>());

    int e;  cin>>e;
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        addEdges(s,d,w);
    }
    display();
    return 0;
}