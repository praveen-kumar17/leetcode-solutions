/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr){
            return nullptr;
        }
        int vall=root->val;
        if(vall < p->val && vall < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(vall > p->val && vall>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
        
    }
};