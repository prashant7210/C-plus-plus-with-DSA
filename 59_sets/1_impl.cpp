#include <iostream>
#include <set>
using namespace std;
int main(){
    // defining
    set<int> s;

    // Insertion
    s.insert(1);
    // s.insert(3);
    s.insert(6);
    s.insert(2);
    s.insert(5);
    // s.insert(4);
    s.insert(7);
    cout<<s.size()<<endl;

    // Trversal
    set<int>::iterator itr;
    for(itr=s.begin(); itr!=s.end(); itr++){
        cout<<*itr<<" ";
    }cout<<endl;

    for(auto val:s){
        cout<<val<<" ";
    }cout<<endl;

    // Deletion
    set<int>::iterator start=s.begin();
    auto last=s.begin();
    advance(start,2);
    advance(last,4);
    s.erase(7);  // O(logN)
    s.erase(start,last);    // O(k)  : k->Length of range
    for(auto val:s){
        cout<<val<<" ";
    }cout<<endl; 

    // find
    (s.find(6)==s.end())? cout<<"Value is not present" : cout<<"Value is present";   
    cout<<endl;
    cout<<*s.lower_bound(2)<<endl;
    cout<<*s.upper_bound(6)<<endl;
    return 0;
}