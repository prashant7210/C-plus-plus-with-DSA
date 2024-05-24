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

void preorder(node* root){
    if(!root)  return;

    cout<<root->val<<" ";

    for(node* child:root->children){
        preorder(child);
    }
}

void inorder(node* root){
    if(!root)  return;

    int childNodes=root->children.size();
    for(int i=0; i<childNodes-1; i++){
        inorder(root->children[i]);
    }
    cout<<root->val<<" ";
    if(childNodes>0)  inorder(root->children[childNodes-1]);
    return;
}

void postorder(node* root){
    if(!root)  return;

    for(node* child:root->children){
        postorder(child);
    }
    cout<<root->val<<" ";
}

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

    cout<<"Preorder: ";   preorder(root);  cout<<endl;
    cout<<"Inorder : ";   inorder(root);  cout<<endl;
    cout<<"Postorder : ";   postorder(root);  cout<<endl;
    cout<<"LevelOrder : ";   levelOrder(root);  cout<<endl;
    return 0;
}

//              A
//     B     C      D      E
//   F   G       H  I  J