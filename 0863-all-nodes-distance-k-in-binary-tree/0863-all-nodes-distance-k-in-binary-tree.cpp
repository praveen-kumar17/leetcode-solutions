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
    void trackparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_check,TreeNode* target){
        queue<TreeNode*> pa;
        pa.push(root);
        while(!pa.empty()){
            TreeNode* curr_node=pa.front();
            pa.pop();
            if(curr_node->left){
                parent_check[curr_node->left]=curr_node;
                pa.push(curr_node->left);
            }
            if(curr_node->right){
                parent_check[curr_node->right]=curr_node;
                pa.push(curr_node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_check;
        trackparents(root,parent_check,target);
        unordered_map<TreeNode*,bool>mpp;
        queue<TreeNode*> q;
        q.push(target);
        mpp[target]=true;
        int curr_len=0;
        while(!q.empty()){
            if(curr_len++==k) break;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !mpp[curr->left]){
                    q.push(curr->left);
                    mpp[curr->left]=true;
                }
                if(curr->right && !mpp[curr->right]){
                    q.push(curr->right);
                    mpp[curr->right]=true;
                }
                if(parent_check[curr] && !mpp[parent_check[curr]]){
                    q.push(parent_check[curr]);
                    mpp[parent_check[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(!q.empty()){
            TreeNode* p=q.front();
            q.pop();
            res.push_back(p->val);
        }
        return res;
    }
};