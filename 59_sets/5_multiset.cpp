#include <iostream>
#include <set>
using namespace std;
int main(){
    multiset<int> ms;  // can store duplicates elements
    ms.insert(1);
    ms.insert(3);
    ms.insert(4);
    ms.insert(3);
    ms.insert(2);
    ms.insert(2);
    for(auto val:ms){
        cout<<val<<" ";
    }cout<<endl;

    ms.erase(3);

    for(auto val:ms){
        cout<<val<<" ";
    }
    return 0;
}