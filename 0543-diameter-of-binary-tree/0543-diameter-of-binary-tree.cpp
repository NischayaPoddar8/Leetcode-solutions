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

    int maxHeight = 0;

    int dfs(TreeNode* node){
        if(!node) return 0;

        int leftHeight = 0;
        if(node->left) leftHeight = dfs(node->left);

        int rightHeight = 0;
        if(node->right) rightHeight = dfs(node->right);

        maxHeight = max(maxHeight,rightHeight+leftHeight);

        return 1+max(leftHeight,rightHeight);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxHeight;
    }
};