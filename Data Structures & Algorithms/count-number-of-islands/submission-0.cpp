class Solution {
public:

    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid,int& n,int& m){
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m&& !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,vis,grid,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(i,j,vis,grid,n,m);
                }
            }
        }
        return count;
    }
};
