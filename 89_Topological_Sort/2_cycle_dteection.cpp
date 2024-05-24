#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x){
    return parent[x]=(parent[x]==x)?x:find(parent, parent[x]);
}

bool Union(int a, int b, vector<int>& parent, vector<int>& rank){
    a=find(parent, a);
    b=find(parent, b);

    if(a==b)  return true;

    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
    }
    else{
        parent[a]=b;
        rank[b]++;
    }
    return false;
}

int main(){
    int n, q;  cin>>n>>q;
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++)  parent[i]=i;
    vector<int> rank(n+1, 0);
    while(q--){
        int a, b;  cin>>a>>b;
        bool t=Union(a, b, parent, rank);
        if(t) cout<<"Cycle Detected";
    }
    return 0;
}