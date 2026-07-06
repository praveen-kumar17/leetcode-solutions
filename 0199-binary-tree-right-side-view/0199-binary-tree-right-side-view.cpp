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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int>res;
        map<int,int>mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int x=p.second;
            mpp[x]=node->val;
            if(node->left!=nullptr){
                q.push({node->left,x+1});
            }
            if(node->right!=nullptr){
                q.push({node->right,x+1});
            }
        }
        for(auto& it:mpp){
            res.push_back(it.second);
        }
        return res;
    }
};