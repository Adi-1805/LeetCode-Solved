class MyStack {
    queue <int> Q;
    public:
    void push(int x) {
        int n = Q.size();
        Q.push(x);
        for(int i = 0; i < n; i++){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop() {
        int x = Q.front();
        Q.pop();
        return x;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */