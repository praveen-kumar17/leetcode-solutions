class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int>vis(n+1,1e9);
        vis[k]=0;
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        q.push({0,k});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int node=it.second;
            int time=it.first;
            if(time>vis[node]){
                continue;
            }
            for(auto itt:adj[node]){
                int n_node=itt.first;
                int n_time=itt.second;
                if(time+n_time<vis[n_node]){
                    vis[n_node]=time+n_time;
                    q.push({time+n_time,n_node});
                }
            }
        }
        int ans=0;;
        for(int i=1;i<=n;i++){
            if(vis[i]==1e9){
                return -1;
            }
            ans=max(ans,vis[i]);
        }
        return ans;
        
    }
};