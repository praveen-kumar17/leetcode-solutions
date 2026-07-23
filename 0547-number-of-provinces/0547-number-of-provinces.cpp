class Solution {
public:
    void dfs(int node ,vector<vector<int>>& isConnected,vector<bool>& vis){
        vis[node]=true;
        for(int i=0;i<isConnected[node].size();i++){
            if(isConnected[node][i]==1 &&!vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;
    }
};