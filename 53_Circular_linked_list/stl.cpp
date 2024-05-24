#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> l1={1,2,3,4,5};
    list<int>::iterator itr1=l1.begin();
    auto itr2=l1.begin();
    cout<<*itr1<<" "<<*itr2<<endl;

    // Advance
    advance(itr1,2);
    cout<<*itr1<<endl;

    // Traversal using range based loops
    for(auto num:l1){
        cout<<num<<" ";
    }

    // Traversal using iterators
    for(auto itr=l1.begin(); itr!=l1.begin(); advance(itr,1)){  // advance(itr,1)=1
        cout<<*itr<<" ";
    }
    cout<<endl;

    // reverse traversal
    for(auto itr=l1.rbegin(); itr!=l1.rend(); itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;

    // Insertion
    l1.insert(l1.begin(),3,0);
    for(auto num:l1){
        cout<<num<<" ";
    }
    cout<<endl;
    auto l=l1.begin();
    auto r=l1.begin();
    advance(l,3);
    advance(r,5);
    l1.insert(l1.end(),l,r);
    for(auto num:l1){
        cout<<num<<" ";
    }
    cout<<endl;

    // Deletion
    auto s=l1.begin();
    auto e=l1.begin();
    l1.erase(s);
    s=l1.begin();
    e=l1.begin();
    advance(e,2);
    l1.erase(s,e);
    s=l1.begin();
    e=l1.begin();
    advance(s,5);
    advance(e,7);
    l1.erase(s,e);
    for(auto num:l1){
        cout<<num<<" ";
    }
    cout<<endl;

    return 0;
}