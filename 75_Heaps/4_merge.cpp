#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<int> &arr, int curr){
    int size = arr.size() - 1;
    while (2 * curr <= size){
        int left = 2 * curr;
        int right = 2 * curr + 1;
        int mx = left;

        if (right <= size && arr[mx] < arr[right])
            mx = right;

        if (arr[curr] >= arr[mx])
            return;
        swap(arr[mx], arr[curr]);
        curr = mx;
    }
}

int main(){
    vector<int> v={-1,4,6,2,5,10};
    for(int e:v){
        cout<<e<<" ";
    }cout<<endl;
    for(int i=(v.size()-1)/2; i>0; i--){
        heapify(v,i);
    }
    for(int e:v){
        cout<<e<<" ";
    }cout<<endl;
    vector<int> a;
    for(int i=0; i<v.size()-1; i++){
        a.push_back(v[i+1]);
    }
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}