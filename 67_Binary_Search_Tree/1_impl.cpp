#include <iostream>
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

    bool serach(int key){
        if(!this->root)  return false;
        node* temp=root;
        while(temp){
            if(temp->val==key)  return true;
            if(temp->val>key)  temp=temp->left;
            else temp=temp->right;
        }
        return false;
    }
};

node* insertRecursively(node* root, int data){
    // base acse
    if(!root)  return new node(data);

    // Recursive case
    if(root->val>data)  root->left=insertRecursively(root->left,data);
    else  root->right=insertRecursively(root->right,data);

    return root;
}

bool searchRecursively(node* root, int key){
    // Base case
    if(!root)  return false;
    if(root->val==key)  return true;

    // Recursive case
    if(root->val>key)  return searchRecursively(root->left,key);
    else  return searchRecursively(root->right,key);
}

node* rightMost(node* root){
    node* currNode=root;
    while(currNode && currNode->right){
        currNode=currNode->right;
    }
    return currNode;
}

node* deleteNode(node* root, int key){
    if(root==NULL)  return root;

    if(root->val>key)  root->left=deleteNode(root->left,key);
    else if (root->val<key)  root->right=deleteNode(root->right,key);
    else{   // Node to be deleted
        if(!root->left && !root->right){  // 0 child Node
            free(root);
            return NULL;
        }
        else if(!root->left){  // only right child
            node* temp=root->right;
            free(root);
            return temp;
        }
        else if(!root->right){  // only left child
            node* temp=root->left;
            free(root);
            return temp;
        }
        else{    // Both child nodes
            node* justSmallerNode=rightMost(root->left);
            root->val=justSmallerNode->val;
            root->left=deleteNode(root->left,justSmallerNode->val);
        }
    }
    return root;
}

node* deleteLeafNodes(node* root){
    if(!root)  return NULL;
    if(!root->left && !root->right)  return NULL;

    root->left=deleteLeafNodes(root->left);
    root->right=deleteLeafNodes(root->right);
    return root;
}

void inorder(node* root){
    if(!root)  return;

    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

void preSucBST(node* root, node* &pre, node* &succ, int key){
    if(!root)  return;

    if(root->val==key){
        // rightmost node of leftsubtree
        if(root->left){
            node* temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            pre=temp;
        }

        // leftmost node of rightsubtree
        if(root->right){
            node* temp=root->right;
            while(temp->left){
                temp=temp->left;
            }
            succ=temp;
        }
        return;
    }

    if(root->val>key){
        succ=root;
        preSucBST(root->left,pre,succ,key);
    }
    else{
        pre=root;
        preSucBST(root->right,pre,succ,key);
    }
}

int main(){
    BST bst;
    bst.insert(3);
    bst.insert(1);
    bst.insert(4);
    bst.root=insertRecursively(bst.root,2);
    bst.root=insertRecursively(bst.root,6);
    inorder(bst.root);
    cout<<endl;

    cout<<bst.serach(5)<<endl;
    cout<<searchRecursively(bst.root,1)<<endl;

    bst.root=deleteNode(bst.root,3);
    inorder(bst.root);     // Check Again
    cout<<endl;

    // bst.root=deleteLeafNodes(bst.root);
    // inorder(bst.root);

    // node* pre=NULL;
    // node* succ=NULL;
    // preSucBST(bst.root,pre,succ,1);
    // cout<<pre->val<<" "<<succ->val<<endl;

    return 0;
}


    //      3
    //   1     4
    //     2      6