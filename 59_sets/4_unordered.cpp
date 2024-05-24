#include <iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> ust;
    ust.insert(1);
    ust.insert(2);
    ust.insert(3);
    ust.insert(1);
    ust.insert(4);

    for(auto val:ust){
        cout<<val<<" ";
    }
    return 0;
}