#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<list<int>> graph;

void addEdges(int src, int dest, bool biDirec=true){
    graph[src].push_back(dest);
    if(biDirec)  graph[dest].push_back(src);
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout<<i<<" -> ";
        for(auto ele:graph[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int v;  cin>>v;
    graph.resize(v,list<int>());

    int e;  cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        addEdges(s,d,false);
    }
    display();
    return 0;
}