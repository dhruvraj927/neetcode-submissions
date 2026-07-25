class Solution {
public:
    int fun(vector<int>& nums,vector<vector<int>>& dp,int t,int i){
        if(t==0) return true;
        if(i==0) return nums[0]==t;

        if(dp[i][t]!=-1) return dp[i][t];
        int n=fun(nums,dp,t,i-1);
        int ta=false;
        if(t>=nums[i]) ta=fun(nums,dp,t-nums[i],i-1);
        return dp[i][t]= n | ta; 
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int n=nums.size();
        if(sum%2==1) return false;
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(nums,dp,sum,n-1);
    }
};
