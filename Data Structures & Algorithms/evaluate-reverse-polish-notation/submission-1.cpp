class Solution {
public:
    bool check(string s){
        return s=="+" || s=="*" || s=="/" || s=="-";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto c:tokens){
            if(check(c)){
                int val = st.top();
                st.pop();
                int val2=st.top();
                st.pop();
                int ans=0;
                char m = c[0];
                switch(m){
                    case '+':
                        ans = val2+val;
                        break;
                    case '-':
                        ans = val2-val;
                        break;
                    case '*':
                        ans = val2*val;
                        break;
                    case '/':
                        ans = val2 / val;
                        break;        
                }
                st.push(ans);
            }
            else{
                int val = stoi(c);
                st.push(val);
            }
        }
        return st.top();
    }
};
