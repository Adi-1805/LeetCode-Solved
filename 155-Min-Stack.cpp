class MinStack {
    stack<pair<int,int>> st;
    
public:
    MinStack() {
        pair<int,int> tp;
        tp.first = -1;
        tp.second = INT_MAX;
    }
    
    void push(int val) {
        int minElement;
        if(st.empty()){
            minElement = val;
        }
        else{
            minElement = min(st.top().second, val);
        }
        st.push({val, minElement});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */