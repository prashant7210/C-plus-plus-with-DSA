#include <bits/stdc++.h>
using namespace std;

struct edge{
    int src;
    int dest;
    int wt;
};

struct DSU{
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++)  parent[i]=i;
    }

    int find(int x){
        return parent[x]=(parent[x]==x?x:find(parent[x]));
    }

    void Union(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b)   return;
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
};

bool cmp(edge e1, edge e2){
    return e1.wt < e2.wt;
}

long long kr(int n, int e, vector<edge>& input){    // Time Complexity : O(ElogE)
    sort(input.begin(), input.end(), cmp);
    DSU dsu(n);
    int edges_count=0;
    int i=0;
    long long ans=0;
    while(edges_count<n-1 and i<e){
        edge curr=input[i];
        int sp=dsu.find(curr.src);
        int dp=dsu.find(curr.dest);
        if(sp!=dp){
            dsu.Union(sp, dp);
            edges_count++;
            ans+=curr.wt;
        }
        i++;
    }
    return ans;
}

int main(){
    int n, e;
    cin>>n>>e;
    vector<edge> v(e);
    for(int i=0; i<e; i++){
        cin>>v[i].src>>v[i].dest>>v[i].wt;
    }
    cout<<kr(n, e, v);
    return 0;
}
