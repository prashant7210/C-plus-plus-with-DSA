#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucket_sort(vector<float>&v);
int main(){
    vector<float>v = {0.22,0.44,0.15,0.39,0.56};
    bucket_sort(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"  ";
    }
    return 0;
}

void bucket_sort(vector<float>&v){
    int n=v.size();
    vector<vector<float>> bucket(n,vector<float>());

    // Inserting elements into bucket
    for(int i=0; i<n; i++){
        int idx = v[i]*n;
        bucket[idx].push_back(v[i]);
    }

    // Sorting individual elements
    for(int i=0; i<n; i++){
        if(!bucket[i].empty()){
            sort(bucket.begin(),bucket.end());
        }
    }

    // Combining all buckets
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<bucket[i].size(); j++){
            v[k++] = bucket[i][j];
        }
    }
}