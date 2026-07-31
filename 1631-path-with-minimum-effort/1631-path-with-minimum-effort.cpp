class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> vis(n,vector<int>(m,1e9));
        vis[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int diff=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return diff;
            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(n_row>=0 && n_col>=0 && n_row<n && n_col<m){
                    int new_diff=max(abs(heights[row][col]-heights[n_row][n_col]),diff);
                    if(new_diff<vis[n_row][n_col]){
                        vis[n_row][n_col]=new_diff;
                        pq.push({new_diff,{n_row,n_col}});

                    }
                }
            }
        }
        return 0;
    }
};