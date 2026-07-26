class Solution {
private:
    bool dfs(int start,int col,vector<vector<int>>& graph,vector<int>& color){
        color[start]=col;
        for(auto it: graph[start]){
            if(color[it]==-1){
                if(dfs(it,!col,graph,color)==false) return false;
            }
            else if(color[it]==col){
                    return false;
                }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            vis[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
               if(dfs(i,0,graph,vis)==false){
                  return false;
                }
            }
        }
        return true;
    }
};