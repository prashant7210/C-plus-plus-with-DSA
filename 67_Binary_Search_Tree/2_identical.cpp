#include <iostream>
#include <vector>
using namespace std;

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

class BST{
    public:
    node* root;
    BST(){
        this->root=NULL;
    }

    void insert(int data){
        node* newNode=new node(data);
        if(!this->root){
            this->root=newNode;
            return;
        }

        node* currNode=root;
        while(true){
            if(currNode->val>data){
                if(!currNode->left){
                    currNode->left=newNode;
                    return;
                }
                currNode=currNode->left;
            }
            else{
                if(!currNode->right){
                    currNode->right=newNode;
                    return;
                }
                currNode=currNode->right;
            }
        }
    }
};

bool identicalBST(vector<int>& v1, vector<int>& v2, int s1,int s2, int mn, int mx){
    // Finding first min and max element
    int i;
    for(i=s1; i<v1.size(); i++){
        if(v1[i]>mn && v1[i]<mx)  break;
    }
    int j;
    for(j=s2; j<v2.size(); j++){
        if(v2[j]>mn && v2[j]<mx)  break;
    }

    // Checking leaf nodes
    if(i==v1.size() && j==v2.size())  return true;

    if((i==v1.size() && j!=v2.size()) || (i!=v1.size() && j==v2.size()))  return false;

    // checking equal value
    if(v1[i]!=v2[j]) return false;

    // recursive
    return identicalBST(v1,v2,s1+1,s2+1,mn,v1[i]) && identicalBST(v1,v2,s1+1,s2+1,v1[i],mx);

}

int main(){
    vector<int> v1={4,2,5,1,3};
    vector<int> v2={4,5,3,2,1};
    cout<<identicalBST(v1,v2,0,0,INT16_MIN,INT16_MAX);
    return 0;
}