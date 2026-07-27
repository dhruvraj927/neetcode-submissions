class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
            }
        }
        int ans=-1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int time=q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            ans=max(ans,time);
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    q.push({time+1,{nr,nc}});
                    grid[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==1)
            return -1;
    }
}

return max(ans,0);

    }
};
