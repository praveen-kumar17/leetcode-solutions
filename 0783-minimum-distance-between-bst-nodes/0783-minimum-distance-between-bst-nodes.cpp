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
    void helper(TreeNode* root,int& min_diff,int& prev){
        if(root==nullptr){
            return;
        }
        helper(root->left,min_diff,prev);
        if(prev!=-1){
            min_diff=min(min_diff,root->val-prev);
        }
        prev=root->val;
        helper(root->right,min_diff,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int min_diff=INT_MAX;
        int prev=-1;
        helper(root,min_diff,prev);
        return min_diff;
    }
};