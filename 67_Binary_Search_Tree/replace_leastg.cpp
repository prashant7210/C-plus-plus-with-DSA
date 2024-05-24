#include <iostream>
using namespace std;
#include <vector>

class node{
    public:
    int val;
    node* left;
    node* right;
    node(int data){
        this->val=data;
        this->left=this->right=NULL;
    }
};

node* insertNode(node* root, int ele, int& succ){
    if(!root)  return new node(ele);

    if(ele<root->val){
        succ=root->val;
        root->left=insertNode(root->left,ele,succ);
    }
    else if(ele>root->val)  root->right=insertNode(root->right,ele,succ);

    return root;
}

void replaceWithGreaterElement(vector<int>& v){
    node* root=NULL;
    for(int i=v.size()-1; i>=0; i--){
        int succ=-1;
        root=insertNode(root,v[i],succ);
        v[i]=succ;
    }
}
int main(){
    vector<int> v={8,3,10,1,6,9,14};
    replaceWithGreaterElement(v);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
