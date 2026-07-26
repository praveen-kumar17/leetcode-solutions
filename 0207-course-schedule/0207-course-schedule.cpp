class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                incomingnodes[it]--;
                if(incomingnodes[it]==0){
                    q.push(it);
                }
            }
        }
        if(cnt==numCourses){ 
            return true;
        }
        return false;
    }
};