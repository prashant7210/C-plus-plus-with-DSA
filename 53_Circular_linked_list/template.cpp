#include <iostream>
using namespace std;

template <typename T>

class node{
    public:
    T val;
    node* next;
    node(T n){
        val=n;
        next=NULL;
    }
};
int main(){
    node<int>* new_node=new node<int> (3);
    cout<<new_node->val<<endl;
    node<string>* node1=new node<string> ("Template class");
    cout<<node1->val<<endl;
    return 0;
}