#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxWindow(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<k; i++){
        while(not dq.empty() and arr[i]>arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    for(int i=k; i<arr.size(); i++){
        if(dq.front()==i-k)  dq.pop_back();
        while(not dq.empty() and arr[i]>arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(arr[dq.front()]);
    }
    return ans;
}

int main(){
    return 0;
}