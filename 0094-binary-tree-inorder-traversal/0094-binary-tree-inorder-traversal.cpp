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

    void dfs(vector<int>&ans,TreeNode* root){

        if(root->left) dfs(ans,root->left);
        ans.push_back(root->val);
        if(root->right) dfs(ans,root->right);

        return;

    }

public:

    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
};