#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<pair<int,int>>> graph;

void addEdges(int src, int dest, int wt, bool biDirec=true){
    graph[src].push_back({dest,wt});
    if(biDirec)  graph[dest].push_back({src,wt});
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
    graph.resize(v,list<pair<int,int>>());

    int e;  cin>>e;
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        addEdges(s,d,w);
    }
    display();
    return 0;
}