#include <iostream>
#include<vector>
using namespace std;

class node{
    public:
    int val;
    vector<node*> children;
    node(int data){
        this->val=data;
    }
};

void preorder(node* root){
    if(!root)  return;

    cout<<root->val<<" ";

    for(node* child:root->children){
        preorder(child);
    }
}

void nextGreater(node* root, int x, node*& ans){
    if(!root)  return;

    if(root->val>x && (!ans || root->val<ans->val))  ans=root;  // Updating ans

    for(auto child:root->children){
        nextGreater(child,x,ans);
    }
}

int main(){
    node* root=new node(20);
    root->children.push_back(new node(8));
    root->children.push_back(new node(22));
    root->children[0]->children.push_back(new node(4));
    root->children[0]->children.push_back(new node(12));
    root->children[0]->children[1]->children.push_back(new node(10));
    root->children[0]->children[1]->children.push_back(new node(14));
    node* ans=NULL;
    nextGreater(root,22,ans);
    !ans? cout<<"NULL":cout<<ans->val;
    return 0;
}