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
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root,int& res){
        if(root==nullptr){
            return 0;
        }
        int left_sum=max(0,dfs(root->left,res));
        int right_sum=max(0,dfs(root->right,res));
        res=max(res,left_sum+right_sum+root->val);
        return max(left_sum,right_sum)+root->val;
    }
};