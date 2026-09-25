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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if(!p && !q) return true;
        if((p && !q) || (!p && q) ||(p->val!=q->val)) return false;

        queue<pair<TreeNode*,TreeNode*>>qu;
        qu.push({p,q});

        while(!qu.empty()){

            int size = qu.size();

            for(int i=0;i<size;i++){
                
                TreeNode* node1 = qu.front().first;
                TreeNode* node2 = qu.front().second;
                qu.pop();

                if((node1->left && !node2->left) || (!node1->left && node2->left)) return false;

                if(node1->left && node2->left) {
                    if(node1->left->val != node2->left->val) return false;
                    qu.push({node1->left,node2->left});
                } 

                if((node1->right && !node2->right) || (!node1->right && node2->right)) return false;

                if(node1->right && node2->right) {
                    if(node1->right->val != node2->right->val) return false;

                    qu.push({node1->right,node2->right});
                }
                
            }   
        }
        
        return true;
    }
};