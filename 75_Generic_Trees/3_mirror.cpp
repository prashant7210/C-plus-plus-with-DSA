#include <iostream>
#include<vector>
#include <queue>
#include <algorithm>
using namespace std;

class node{
    public:
    int val;
    vector<node*> children;
    node(int data){
        this->val=data;
    }
};

void levelOrder(node* root){
    if(!root)  return;

    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        int levelSize=q.size();
        while(levelSize--){
            node* curr=q.front();
            cout<<curr->val<<" ";
            q.pop();
            for(node* child:curr->children){
                q.push(child);
            }
        }
        cout<<endl;
    }
}

void mirror(node*& root){
    if(!root)  return;
    if(root->children.size()<2)  return;

    reverse(root->children.begin(),root->children.end());
    for(node* child:root->children){
        mirror(child);
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
    root->children[0]->children[1]->children.push_back(new node(16));
    root->children[0]->children[1]->children.push_back(new node(10));
    
    levelOrder(root); cout<<endl;

    mirror(root);
    levelOrder(root);

    return 0;
}