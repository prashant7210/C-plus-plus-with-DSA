#include <bits/stdc++.h>
using namespace std;

struct edge{
    int src;
    int dest;
    int cost;
};

struct DSU{
    vector<int> parent;
    vector<int> rank;
    int connected_comp;
    DSU(int n){
        parent.resize(n);
        for(int i=0; i<n; i++)  parent[i]=i;
        rank.resize(n, 0);
        connected_comp=n;
    }

    int find(int x){
        return parent[x]=(parent[x]==x?x:find(parent[x]));
    }

    void Union(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b)  return;
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
        connected_comp--;
    }
};

bool cmp(edge e1, edge e2){
    return e1.cost<e2.cost;
}

int min_cost_to_connect_all_cities(vector<edge>& input, int n){
    DSU dsu(n);
    sort(input.begin(), input.end(), cmp);
    int i=0;
    int edge_count=0;
    int ans=0;
    while(i<input.size() and edge_count<n){
        edge curr=input[i];
        int s=dsu.find(curr.src);
        int d=dsu.find(curr.dest);
        if(s!=d){
            dsu.Union(s, d);
            edge_count++;
            ans+=curr.cost;
        }
        i++;
    }
    return dsu.connected_comp>1?-1:ans;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<edge> v(e);
    for(int i=0; i<e; i++)  cin>>v[i].src>>v[i].dest>>v[i].cost;
    cout<<min_cost_to_connect_all_cities(v, n);
    return 0;
}