#include <iostream>
#include <vector>
using namespace std;

// MIN heap
void insertKey(vector<int>& v, int key){
    if(v.size()==1)  return;

    v.emplace_back(key);
    int s=v.size()-1;
    while(s/2>0 && v[s/2]>v[s]){
        swap(v[s],v[s/2]);
        s/=2;
    }
}

void deleteNode(vector<int>& v){
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    int size=v.size()-1;
    int curr=1;
    while(2*curr<=size){
        int left=2*curr;
        int right=2*curr+1;
        int minChild=left;

        if(right<=size && v[right]<minChild)  minChild=right;

        if(v[minChild]>=v[curr]) return;

        swap(v[curr],v[minChild]);
        curr=minChild;
    }
}

int main(){
    vector<int> v={-1,10,20,30,40,50};
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    insertKey(v,5);

    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    deleteNode(v);
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}