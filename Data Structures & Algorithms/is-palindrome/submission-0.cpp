class Solution {
public:
    bool isPalindrome(string s) {
        int f=0,l=s.length()-1;
        while(f<l){
            char u=tolower(s[f]);
            char v=tolower(s[l]);
            if(((u>='a' && u<='z') || (u >= '0' && u <= '9')) && ((v>='a' && v<='z') || (v >= '0' && v <= '9'))){
                if(u!=v) return false;
                else{
                    f++;
                    l--;
                }
            }
            else if((u>='a' && u<='z') || (u >= '0' && u <= '9')) l--;
            else if((v>='a' && v<='z') || (v >= '0' && v <= '9')) f++;
            else {
                f++;
                l--;
            }
        }
        return true;
    }
};
