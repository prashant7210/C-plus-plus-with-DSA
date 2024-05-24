#include <iostream>
#include<vector>
#include <queue>
using namespace std;

class node{
    public:
    char val;
    vector<node*> children;
    node(char data){
        this->val=data;
    }
};

void serialisedTree(node* root, string &ans){
    if(!root)  return;

    ans+=to_string(root->val)+ " : " +to_string(root->children.size())+" : ";
    for(node* child:root->children){
        ans+=to_string(child->val)+",";
    }
    if(root->children.size()) ans.pop_back();
    ans+="\n";
    for(node* child:root->children){
        serialisedTree(child,ans);
    }
}

int main(){
    node* root=new node('A');
    root->children.push_back(new node('B'));
    root->children.push_back(new node('C'));
    root->children.push_back(new node('D'));
    root->children.push_back(new node('E'));

    root->children[0]->children.push_back(new node('F'));
    root->children[0]->children.push_back(new node('G'));

    root->children[2]->children.push_back(new node('H'));
    root->children[2]->children.push_back(new node('I'));
    root->children[2]->children.push_back(new node('J'));
    
    string s="";
    serialisedTree(root,s);
    cout<<s;

    return 0;
}