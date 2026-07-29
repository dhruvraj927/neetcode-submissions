class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        for(auto x:nums){
            sum+=x;
            }
        long long  n = nums.size();

        long long total = 1LL * n*(n+1) /2;
        return (int)(total-sum);
    }
};
