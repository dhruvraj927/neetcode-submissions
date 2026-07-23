class Solution {
public:
    int fun(vector<int>& nums,vector<int>& dp,int i){
        if(i<0) return 0;
        if(i==0) return nums[0];
        if(dp[i]!=-1) return dp[i];
        int not_take=fun(nums,dp,i-1);
        int take=nums[i]+fun(nums,dp,i-2);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n,-1);
       return fun(nums,dp,n-1); 
    }
};
