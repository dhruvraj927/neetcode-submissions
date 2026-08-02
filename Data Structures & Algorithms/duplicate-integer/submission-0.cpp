class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>s;
        for(auto x:nums){
            if(!s.count(x)) s.insert(x);
            else return true;
        }
        return false;
    }
};