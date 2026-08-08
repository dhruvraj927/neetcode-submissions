class Solution {
public:
    int fun(int amount,vector<int>& coins,vector<vector<int>>&dp,int i){
        if(i==0) {
           if(amount%coins[i]==0) return 1;;
           return 0;
        }
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int not_take = fun(amount,coins,dp,i-1);
        int take=0;
        if(coins[i]<=amount){
            take = fun(amount-coins[i],coins,dp,i);
        }
        return dp[i][amount] = not_take+take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(amount,coins,dp,n-1);
    }
};
