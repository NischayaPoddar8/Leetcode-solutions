/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

    void dfs(TreeNode* node,vector<int>&ans,int level){
        if(!node) return;

        if(level==ans.size()) ans.push_back(node->val);

        if(node->right) dfs(node->right,ans,level+1);
        if(node->left) dfs(node->left,ans,level+1);

        return;
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }
};