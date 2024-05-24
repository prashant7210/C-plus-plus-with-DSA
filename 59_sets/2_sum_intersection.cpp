#include <iostream>
#include<vector>
#include <set>
using namespace std;

int sumOfIntersection(vector<int> &v1, vector<int>&v2){
    set<int> s;

    // Insert elements of v1 into set : O(n*logt)
    for(int i=0; i<v1.size(); i++){
        s.insert(v1[i]);
    }

    int sum=0;
    // Search elements of sets in v2 : O(m*logt)
    for(int i=0; i<v2.size(); i++){
        if(s.find(v2[i])!=s.end()){
            sum+=v2[i];
        }
    }
    return sum;
}

int main(){
    vector<int> v1={1,2,4,6,5,7,1,7};
    vector<int> v2={1,5,4,0,0,0,0,3,10};
    cout<<sumOfIntersection(v1,v2);
    return 0;
}