class Solution {
public:
    int bfs(int r,int c,vector<vector<int>>& vis,vector<vector<int>>grid,int& n ,int& m){
        int count=0;
        vis[r][c]=1;
        queue<pair<int,int>>q;
        q.push({r,c});
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};

        while(!q.empty()){
            int row=q.front().first;
            int col = q.front().second;
            q.pop();
            
            count++;

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});

                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();             
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]  && grid[i][j]==1){
                    int x=bfs(i,j,vis,grid,n,m);
                    cout << x << endl;
                     ans = max(ans,x);
                }
            }
        }
        return ans;
    }
};
