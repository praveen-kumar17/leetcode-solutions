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
    int search(vector<int>& inorder,int left,int right,int val){
        for(int i=left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder,int& post_idx,int left,int right){
        if(left>right){
            return nullptr;
        }
        TreeNode* root=new TreeNode(postorder[post_idx]);
        int idx=search(inorder,left,right,postorder[post_idx]);
        post_idx--;
        root->right=helper(inorder,postorder,post_idx,idx+1,right);
        root->left=helper(inorder,postorder,post_idx,left,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_idx=postorder.size()-1;
        return helper(inorder,postorder,post_idx,0,inorder.size()-1);
    }
};