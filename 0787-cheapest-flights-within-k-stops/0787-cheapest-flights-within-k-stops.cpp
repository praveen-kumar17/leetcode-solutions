class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int>dis(n,1e9);
        dis[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k){
                continue;
            }
            for(auto itt:adj[node]){
                int n_node=itt.first;
                int new_cost=itt.second;
                if(cost+new_cost<dis[n_node] && stops<=k){
                    dis[n_node]=cost+new_cost;
                    q.push({stops+1,{n_node,cost+new_cost}});
                }
            }
        }
        if(dis[dst]==1e9){
            return -1;
        }
        return dis[dst];
        
    }
};