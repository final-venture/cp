class MyQueue {
public:
    stack<int> q1, q2;
    MyQueue() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while (!q1.empty()) {
            q2.push(q1.top());
            q1.pop();
        }
        int ret = q2.top();
        q2.pop();
        while (!q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }
        return ret;
    }
    
    int peek() {
        while (!q1.empty()) {
            q2.push(q1.top());
            q1.pop();
        }
        int ret = q2.top();
        while (!q2.empty()) {
            q1.push(q2.top());
            q2.pop();
        }
        return ret;
    }
    
    bool empty() {
        return (q1.empty());
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