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

    int maxi = -1001;

    int dfs(TreeNode* node){

        if(!node) return 0;

        int leftSum = 0;
        if(node->left)leftSum = dfs(node->left);

        int rightSum = 0;
        if(node->right) rightSum = dfs(node->right);

        maxi = max({maxi,node->val+leftSum+rightSum,node->val,node->val+leftSum,node->val+rightSum});

        if(leftSum>0 || rightSum>0) return node->val + max(leftSum,rightSum);
        return node->val;
    }


public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};