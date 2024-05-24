#include <iostream>
#include <unordered_map>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->val=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int solve(TreeNode* root, int targetSum, unordered_map<long int, int>m, long int currSum){
        if(!root)  return 0;

        currSum+=root->val;
        int tc=m[currSum-targetSum];

        m[currSum]++;
        tc+=(solve(root->left,targetSum,m,currSum)+solve(root->right,targetSum,m,currSum));
        m[currSum]--;  // backtrack
        return tc;
    }

int main(){
    return 0;
}