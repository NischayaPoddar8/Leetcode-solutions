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

        int leftSum = max(0,dfs(node->left)); // if no node exists leftSum is set 0

        int rightSum = max(0,dfs(node->right));

        maxi = max(maxi,node->val+leftSum+rightSum);

        return node->val+max(leftSum,rightSum);
    }


public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};