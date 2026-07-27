class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>grid,int & n,int& m){
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='O' && !vis[nr][nc] ){
                dfs(nr,nc,vis,grid,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O') dfs(i,0,vis,grid,n,m);
        }
        for(int i=0;i<n;i++){
            if(!vis[i][m-1] && grid[i][m-1]=='O') dfs(i,m-1,vis,grid,n,m);
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]=='O') dfs(0,i,vis,grid,n,m);
        }
        for(int i=0;i<m;i++){
            if(!vis[n-1][i] && grid[n-1][i]=='O') dfs(n-1,i,vis,grid,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0) grid[i][j]='X';
                // else grid[i][j]=='O';
            }
        }
        
    }
};
