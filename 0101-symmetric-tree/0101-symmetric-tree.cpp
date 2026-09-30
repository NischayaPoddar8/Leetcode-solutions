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
            int s = q.size();

            for(int i=0;i<s;i++){
                TreeNode* node1 = q.front().first;
                TreeNode* node2 = q.front().second;
                q.pop();

                if(node1->left && node2->right){
                    if(node1->left->val != node2->right->val) return false;
                    else q.push({node1->left,node2->right});
                }
                else if((node1->left && !node2->right) || (!node1->left && node2->right)) return false;

                if(node1->right && node2->left){
                    if(node1->right->val != node2->left->val) return false;
                    else q.push({node1->right,node2->left});
                }
                else if((node1->right && !node2->left) || (!node1->right && node2->left)) return false;
            }
        }

        return true;
    }
};