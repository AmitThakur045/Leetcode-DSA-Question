class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(val < min)
            min = val;
        s.push(val);
        s.push(min);
    }
    
    void pop() {
        s.pop();
        s.pop();
        if(!s.empty())
            min = s.top();
        else
            min =INT_MAX;
    }
    
    int top() {
        s.pop();
        int res = s.top();
        s.push(min);
        return res;
    }
    
    int getMin() {
        return min;
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
