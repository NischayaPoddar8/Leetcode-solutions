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

    void dfs(vector<int>&ans ,TreeNode* node){

        if(node->left) dfs(ans,node->left);
        if(node->right) dfs(ans,node->right);
        ans.push_back(node->val);

    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        dfs(ans,root);
        return ans;
    }
};