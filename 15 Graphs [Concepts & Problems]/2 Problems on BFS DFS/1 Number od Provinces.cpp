class Solution {
    public:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        if(!vis[node]) vis[node]=1;
    
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
        
    }
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<vector<int>>adj(n+1);
    
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    if(i!=j && isConnected[i-1][j-1]==1){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            vector<int>vis(n+1,0);
            int cnt =0;
            for(int i=1;i<=n;++i){
                if(!vis[i]){
                    cnt++;
                    dfs(i, vis, adj);
                }
            }
            return cnt;
        }
    };