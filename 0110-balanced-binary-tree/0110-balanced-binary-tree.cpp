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

    int dfs(TreeNode* root,bool &balanced){

        if(root==NULL) return 0;

        int leftHeight = 0;
        if(root->left) leftHeight = dfs(root->left,balanced);

        int rightHeight = 0;
        if(root->right) rightHeight = dfs(root->right,balanced);

        if(abs(leftHeight-rightHeight)>1) balanced = false;
        return 1+max(leftHeight,rightHeight);

    }

public:
    bool isBalanced(TreeNode* root) {
        bool balanced = true;
        dfs(root,balanced);
        return balanced;
    }
};