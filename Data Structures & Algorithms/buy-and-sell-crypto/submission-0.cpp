class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini=p[0],ans=0;
        for(int i=1;i<p.size();i++){
            int sell = p[i] - mini;
            mini=min(mini,p[i]);
            ans=max(ans,sell);
        }
        return ans;
    }
};
