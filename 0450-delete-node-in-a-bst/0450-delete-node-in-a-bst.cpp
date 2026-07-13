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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* node=root;
        while(node!=nullptr){
            if(node->val>key){
                if(node->left!=nullptr && node->left->val==key){
                    node->left= helper(node->left);
                    break;
                }else{
                    node=node->left;
                }
            }else{
                if(node->right!=nullptr && node->right->val==key){
                    node->right= helper(node->right);
                    break;
                }else{
                    node=node->right;
                }
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==nullptr){
            return root->right;
        }
        else if(root->right==nullptr){
            return root->left;
        }
        TreeNode* right=root->right;
        TreeNode* leftmostright=leftmo(root->left);
        leftmostright->right=right;
        return root->left;
        
    }
    TreeNode* leftmo(TreeNode* root){
        if(root->right==nullptr){
            return root;
        }
        return leftmo(root->right);
    }
};