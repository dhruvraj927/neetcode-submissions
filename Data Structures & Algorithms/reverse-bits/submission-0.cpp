class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=0;
        int ans=0;
        while(i<32){
            ans=ans<<1;
            if(n&1) ans = ans | 1;
            
            n=n>>1;
            i++;
        }
        return ans;
    }
};
