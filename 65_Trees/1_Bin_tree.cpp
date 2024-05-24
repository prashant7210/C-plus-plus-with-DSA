#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

class node{
public:
    int val;
    node* left;
    node* right;
    node(int data){
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};

// DFS : Depth first search

void preorderTraversal(node* root){   // root left right
    // base case
    if(!root)  return;

    // Recursive case
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inOrderTraversal(node* root){    // left root right
    // base case
    if(!root)  return;

    // Recursive case
    inOrderTraversal(root->left);
    cout<<root->val<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(node* root){    // left right root
    // base case
    if(!root)  return;

    // Recursive case
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->val<<" ";
}

// BFS : Breadth first search
void levelOrderTrversal(node* root){
    if(!root)  return;

    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        int levelSize=q.size();
        while(levelSize--){
            node* currNode=q.front();
            cout<<q.front()->val<<" ";
            q.pop();
            if(currNode->left) q.push(currNode->left);
            if(currNode->right) q.push(currNode->right);
        }
        cout<<endl;
    }
}

int maxDepth(node* root){
    // base case
    if(!root)  return 0;

    // recursive case
    int leftDepth=maxDepth(root->left);
    int rightDepth=maxDepth(root->right);

    return max(leftDepth,rightDepth)+1;
}

int leafNodes(node* root, int ans){
    // base case
    if(!root)  return 0;
    if(!root->left && !root->right)  return 1;

    // Recursive case
    int leftLeaves=leafNodes(root->left,ans);
    int rightLeaves=leafNodes(root->right,ans);

    return ans+leftLeaves+rightLeaves;
}

vector<int> rightView(node* root){
    vector<int> ans;
    if(!root)  return ans;
    // Level order Traversal
    queue<node*> q;
    q.push(root);
    while(not q.empty()){
        int currLevelNodes=q.size();
        while(currLevelNodes){
            node* currNode=q.front();
            q.pop();
            if(currLevelNodes==1)  ans.push_back(currNode->val);
            if(currNode->left)  q.push(currNode->left);
            if(currNode->right)  q.push(currNode->right);
            currLevelNodes--;
        }
    }
    return ans;
}

vector<int> leftView(node* root){
    vector<int> ans;
    if(!root)  return ans;

    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int levelSize=q.size();
        while(levelSize){
            node* currNode=q.front();
            q.pop();
            if(levelSize==1)  ans.push_back(currNode->val);

            if(currNode->right)  q.push(currNode->right);
            if(currNode->left)  q.push(currNode->left);
            levelSize--;
        }
    }
    return ans;
}

vector<int> topView(node* root){
    vector<int> ans;
    if(!root)  return ans;

    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));

    map<int,int> m;

    while(not q.empty()){
        int nodesAtCurrLevel=q.size();
        while(nodesAtCurrLevel--){
            pair<node*,int> p=q.front();
            node* currNode=p.first;
            int currCol=p.second;
            q.pop();

            if(m.find(currCol)==m.end())  m[currCol]=currNode->val;
            if(currNode->left)  q.push(make_pair(currNode->left,currCol-1));
            if(currNode->right)  q.push(make_pair(currNode->right,currCol+1));
        }
    }

    for(auto i:m){
        ans.push_back(i.second);
    }

    return ans;
}

vector<int> reverseLevelOrder(node* root){
    vector<int> ans;
    if(!root)  return ans;

    queue<node*> q;
    stack<node*> s;

    q.push(root);
    while(!q.empty()){
        int levelSize=q.size();
        while(levelSize--){
            node* currNode=q.front();
            q.pop();
            s.push(currNode);

            if(currNode->right)  q.push(currNode->right);
            if(currNode->left)  q.push(currNode->left);
        }
    }

    while(not s.empty()){
        ans.push_back(s.top()->val);
        s.pop();
    }
    return ans;
}

int main(){
    node* root=new node(2);
    root->left=new node(4);
    root->right=new node(10);
    root->left->left=new node(6);
    root->left->left->right=new node(12);
    root->left->right=new node(5);
    root->right->right=new node(11);

    cout<<"Pre Order : ";
    preorderTraversal(root);
    cout<<endl<<"Inorder : ";
    inOrderTraversal(root);
    cout<<endl<<"Post Order : ";
    postOrderTraversal(root);
    cout<<endl<<"Level Order : \n";
    levelOrderTrversal(root);
    cout<<"Max Depth : "<<maxDepth(root)<<endl;
    cout<<"Leaf Node : "<<leafNodes(root,0)<<endl;
    cout<<"Right View : ";
    vector<int> ans=rightView(root);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    cout<<"\nTop View : ";

    vector<int> top=topView(root);
    for(int i=0; i<top.size(); i++){
        cout<<top[i]<<" ";
    }
    cout<<endl<<"Reverse Order : ";

    vector<int> rev=reverseLevelOrder(root);
    for(int i=0; i<rev.size(); i++){
        cout<<rev[i]<<" ";
    }
    cout<<endl<<"Left View : ";

    vector<int> left=leftView(root);
    for(int i=0; i<left.size(); i++){
        cout<<left[i]<<" ";
    }

    return 0;
}