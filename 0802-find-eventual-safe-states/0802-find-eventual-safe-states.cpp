class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>> revadj(v);
        vector<int> incomingnodes(v,0);
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
               revadj[it].push_back(i);
               incomingnodes[i]++;
            }
        }
        queue<int>q;
        vector<int>safenodes;
        for(int i=0;i<v;i++){
            if(incomingnodes[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safenodes.push_back(node);
            for(auto it:revadj[node]){
                incomingnodes[it]--;
                if(incomingnodes[it]==0){
                    q.push(it);
                }
            }
        }
        sort(safenodes.begin(),safenodes.end());
        return safenodes;
    }
};