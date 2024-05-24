#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int>&input, int target);
int main(){
    vector<int>v={2,5,7,9,10,15,20};
    int target = 9;
    cout<<binary_search(v,target);
    return 0;
}

int binary_search(vector<int>&input, int target){
    int lo=0;
    int hi=input.size()-1;
    while(hi>=lo){
        int mid = (lo+hi)/2;
        if(target == input[mid])  return mid;
        else if(target>input[mid])  lo=mid+1;
        else  hi=mid-1;
    }
    return -1;
}