class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int& n ,int& m){
        if(i>n || j>m || i<0 || j<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = 1;
        int down = 1;
        int left = 1;
        int right = 1;

        // UP
        if (i - 1 >= 0 &&
            matrix[i][j] < matrix[i-1][j]) {

            up = 1 + dfs(i-1, j, matrix, dp, n, m);
        }

        // DOWN
        if (i + 1 < n &&
            matrix[i][j] < matrix[i+1][j]) {

            down = 1 + dfs(i+1, j, matrix, dp, n, m);
        }

        // LEFT
        if (j - 1 >= 0 &&
            matrix[i][j] < matrix[i][j-1]) {

            left = 1 + dfs(i, j-1, matrix, dp, n, m);
        }

        // RIGHT
        if (j + 1 < m &&
            matrix[i][j] < matrix[i][j+1]) {

            right = 1 + dfs(i, j+1, matrix, dp, n, m);
        }

        return dp[i][j] = max({up, down, left, right});
    

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                   ans= max(ans,dfs(i,j,matrix,dp,n,m));
                }
                else ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
