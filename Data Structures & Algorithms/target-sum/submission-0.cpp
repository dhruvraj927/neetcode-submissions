class Solution {
public:
    int fun(vector<int>& nums, int t,int i, map<pair<int,int>,int>& dp){
        //if(t==0) return 1;
        if(i<0) return t==0;
        if(dp.count({i,t})) return dp[{i,t}];
        int pos = fun(nums,t+nums[i],i-1,dp);
        int neg=fun(nums,t-nums[i],i-1,dp);
        return dp[{i,t}] = pos+neg;

    }
    int findTargetSumWays(vector<int>& nums, int t) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(t+1,-1));
        map<pair<int,int>,int>dp;
        return fun(nums,t,n-1,dp);
    }
};
