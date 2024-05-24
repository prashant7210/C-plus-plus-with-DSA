#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main(){
    vector<int> v={2,4,1,3,7,5,6};
    set<int> s;
    for(auto val:v){
        s.insert(val);
    }
    set<int>::iterator itr=s.begin();
    advance(itr,5);
    cout<<*itr;
    return 0;
}