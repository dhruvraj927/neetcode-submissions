class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        vector<int>nse(n,n),pse(n,-1); // store the index not value
        stack<int>s1,s2;    // s1->nse , s2->pse
        
        for(int i=n-1;i>=0;i--){
            while(!s1.empty() && h[s1.top()]>=h[i] ){
                s1.pop();
            }
            if(s1.empty()) nse[i]=n;
            else{
                nse[i]=s1.top();
            }
            s1.push(i);
        }
         for(int i=0;i<n;i++){
            while(!s2.empty() && h[s2.top()]>=h[i] ){
                s2.pop();
            }
            if(s2.empty()) pse[i]=-1;
            else{
                pse[i]=s2.top();
            }
            s2.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,h[i]*(nse[i]-pse[i]-1));
        }
        return ans;

    }
};
