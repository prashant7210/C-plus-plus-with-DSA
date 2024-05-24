#include <bits/stdc++.h>
using namespace std;

struct item{
    int value;
    int weight;
};

//  Time Complexity : O(nlogn)
// Space Complexity : O(sorting)

bool cmp(item i1, item i2){
    // Custom comparatof for sorting
    double v_w_i1=static_cast<double> (i1.value)/i1.weight;
    double v_w_i2=static_cast<double> (i2.value)/i2.weight;

    return v_w_i1 > v_w_i2;
}

double fractionalKnapsack(int w, vector<item>& items){
    sort(items.begin(), items.end(), cmp);
    double ans=0;
    for(const auto &it:items){
        if(it.weight<=w){
            ans+=it.value;
            w-=it.weight;
        }
        else{
            double fraction=static_cast<double>(w)/it.weight;
            ans+=fraction*it.value;
            w=0;
        }
    }

    return ans;
}

int main(){
    int n,W;
    cin>>n>>W;

    vector<item> items;
    for(int i=0; i<n; i++){
        int v,w;
        cin>>v>>w;
        item it;
        it.value=v;
        it.weight=w;
        items.push_back(it);
    }

    cout<<fractionalKnapsack(W,items);
    return 0;
}