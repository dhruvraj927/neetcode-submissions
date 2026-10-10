class MinStack {
public:
    stack<int>s;
    stack<int>min_st;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(min_st.empty()) min_st.push(val);
        else {
            int val = min(val,min_st.top());
            min_st.push(val);
        }
    }
    
    void pop() {
        s.pop();
        min_st.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
