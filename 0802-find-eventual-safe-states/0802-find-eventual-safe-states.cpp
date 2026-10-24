class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> incoming_nodes(v,0);
        vector<int> ans;
        vector<vector<int>> nodes(v);
        for(int i=0;i<v;i++){
            for(auto& x:graph[i]){
                incoming_nodes[i]++;
                nodes[x].push_back(i);
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(incoming_nodes[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto& x:nodes[node]){
                incoming_nodes[x]--;
                if(incoming_nodes[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};