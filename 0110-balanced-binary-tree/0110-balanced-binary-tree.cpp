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

        int leftHeight = 0;
        if(root->left) leftHeight = dfs(root->left);

        int rightHeight = 0;
        if(root->right) rightHeight = dfs(root->right);

        if(leftHeight==-1) return -1; // Immediately return
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight)>1) return -1; // unbalanced
        return 1+max(leftHeight,rightHeight);

    }

public:
    bool isBalanced(TreeNode* root) {
        int balanced = dfs(root);
        return balanced==-1 ? false : true;
    }
};