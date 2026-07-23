class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        map<char,int>mpp;
        int f=0 , l=0;
        while(l<s.length()){
            mpp[s[l]]++;
            if(mpp[s[l]]==1) len=max(len,l-f+1);
            while(mpp[s[l]]!=1 && f<l){
                mpp[s[f]]--;
                f++;
            }
            l++;
        } 
        return len;
    }
};
