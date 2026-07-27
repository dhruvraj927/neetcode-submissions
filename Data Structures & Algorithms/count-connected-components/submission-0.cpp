class Solution {
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis){
        vis[node]=1;
        for(auto adjnode:adj[node]){
            if(!vis[adjnode]) dfs(adjnode,adj,vis);
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);
        for(auto temp:edges){
            int u = temp[0];
            int v = temp[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;

    }
};
