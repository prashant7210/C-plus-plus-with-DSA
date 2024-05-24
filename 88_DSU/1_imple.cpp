#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& parent, int x){
    return (parent[x]==x)?x:find(parent, parent[x]);
}

void Union(int a, int b, vector<int>& parent, vector<int>& rank){
    a=find(parent, a);
    b=find(parent, b);
    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
    }
    else{
        parent[a]=b;
        rank[b]++;
    }
}

int main(){
    int n, q;  cin>>n>>q;
    vector<int> parent(n+1);
    for(int i=0; i<=n; i++)  parent[i]=i;
    vector<int> rank(n+1, 0);
    while(q--){
        string str;  cin>>str;
        if(str=="union"){
            int a, b;  cin>>a>>b;
            Union(a, b, parent, rank);
        }
        else{
            int x;  cin>>x;
            cout<<find(parent,x)<<endl;;
        }
    }
    return 0;
}