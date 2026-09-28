class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> incomingnodes(numCourses,0);
        queue<int> q;
        for(auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            incomingnodes[edge[0]]++;
        }
        for(int i=0;i<numCourses;i++){
            if(incomingnodes[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            cnt++;
            q.pop();
            for(int x:adj[node]){
                incomingnodes[x]--;
                if(incomingnodes[x]==0){
                    q.push(x);
                }
            }
        }
        if(cnt==numCourses){
            return true;
            }
        return false;
    }
};