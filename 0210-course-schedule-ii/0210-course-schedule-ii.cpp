class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incomingnodes(numCourses,0);
        for(auto edge :prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
            incomingnodes[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(incomingnodes[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                incomingnodes[it]--;
                if(incomingnodes[it]==0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};