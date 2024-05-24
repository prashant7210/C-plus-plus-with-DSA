#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    unordered_multiset<int> ums;
    ums.insert(1);
    ums.insert(2);
    ums.insert(1);
    ums.insert(3);
    ums.insert(1);
    ums.insert(4);
    ums.insert(5);
    ums.insert(6);
    ums.insert(1);

    for(auto val:ums){
        cout<<val<<" ";
    }
    return 0;
}