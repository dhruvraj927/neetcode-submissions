class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int f=0,l=n-1;
        while(f<l){
            if(numbers[f]+numbers[l] == target) return {f+1,l+1};
            else if(numbers[f]+numbers[l] > target) l--;
            else f++;
        }
        return {};
    }
};
