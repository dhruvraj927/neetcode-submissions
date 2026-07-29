class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>s;
        for(int i=0;i<nums.size();i++){
            s.push_back({nums[i],i});
        }
        sort(s.begin(),s.end());

        int i=0,j=nums.size()-1;
        vector<int>ans(2);
        while(i<j){
            if(s[i].first + s[j].first == target){
                ans[0] = s[i].second ;
                ans[1] = s[j].second;
                break;
            }
            else if(s[i].first + s[j].first > target){
                j--;
            }
            else i++;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
