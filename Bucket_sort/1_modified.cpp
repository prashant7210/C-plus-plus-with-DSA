#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucket_sort(vector<float>&v);
int main(){
    vector<float>v = {0.22,0.44,0.15,0.39,0.56,1.45};
    bucket_sort(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"  ";
    }
    return 0;
}

void bucket_sort(vector<float>&v){
    int n=v.size();
    vector<vector<float>> bucket(n,vector<float>());

    //Finding maximum and minimum elements
    float min_ele=v[0],max_ele=v[0];
    for(int i=0; i<n; i++){
        max_ele = max(max_ele,v[i]);
        min_ele = min(min_ele,v[i]);
    }
    float range = (max_ele-min_ele)/n;

    // Inserting elements into bucket
    for(int i=0; i<n; i++){
        int idx = (v[i]-min_ele)/range; 
        //Boundary elements
        float diff = ((v[i]-min_ele)/range)-idx;
        if(diff==0 && v[i]!=min_ele)  bucket[idx-1].push_back(v[i]);
        else  bucket[idx].push_back(v[i]);
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