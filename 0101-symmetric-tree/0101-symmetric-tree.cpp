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
public:
    bool isSymmetric(TreeNode* root) {

        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        if(root->left->val != root->right->val) return false;

        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root->left,root->right});

        while(!q.empty()){

            auto [node1,node2] = q.front();
            q.pop();

            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val != node2->val) return false;

            q.push({node1->left,node2->right});
            q.push({node1->right,node2->left});
        }

        return true;
    }
};