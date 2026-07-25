class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int index=0;
        int maxlen=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            maxlen=1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
            dp[i][i+1]=true;
            maxlen=2;
            index=i;
            }

        }
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        maxlen=len;
                        index=i;
                    }
                }
            }
        }
        return s.substr(index,maxlen);
    }
};
