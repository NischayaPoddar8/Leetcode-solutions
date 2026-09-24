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

    int dfs(TreeNode* root){

        if(root==NULL) return 0;

        int leftDepth = 0;
        int rightDepth = 0;
        if(root->left)  leftDepth = 1+dfs(root->left);
        if(root->right) rightDepth = 1+dfs(root->right);

        return max(leftDepth,rightDepth);
    }

public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return 1+dfs(root);
    }
};