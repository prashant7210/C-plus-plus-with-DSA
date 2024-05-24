#include <bits/stdc++.h>
using namespace std;
struct meeting{
    int start;
    int end;
    int idx;
};
bool cmp(meeting m1, meeting m2){
    return m1.end < m2.end;
}
int ans=1;

void maxMeeting(vector<meeting>& v){
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].idx<<" ";
    meeting last=v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i].start>last.end){
            ans++;
            cout<<v[i].idx<<" ";
            last=v[i];
        }
    }
}
int main(){
    int n;  cin>>n;
    int i=0;
    vector<meeting> v;
    while(n--){
        int s,e;
        cin>>s>>e;
        meeting m;
        m.start=s;
        m.end=e;
        i++;
        m.idx=i;
        v.push_back(m);
    }
    maxMeeting(v);
    cout<<endl<<ans;
    return 0;
}