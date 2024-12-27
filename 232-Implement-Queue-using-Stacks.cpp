class MyQueue {
    stack<int> input, output;
public:
    void push(int x) {
        // pop everything out of i/p stack and push in o/p stack
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        // push new element in i/p stack
        input.push(x);

        // pop everything out of o/p stack and push in i/p stack so that the first added element is at the front(top) of i/p stack
        while (!output.empty()) {
            input.push(output.top());
            output.pop();
        }
    }
    
    int pop() {
        if (input.empty()) return -1;
        int val = input.top();
        input.pop();
        return val;
    }
    
    int peek() {
        if (input.empty()) return -1;
        return input.top();
    }
    
    bool empty() {
        return (input.empty());

    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */