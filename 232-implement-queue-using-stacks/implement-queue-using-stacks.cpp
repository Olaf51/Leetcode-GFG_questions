class MyQueue {
public:
stack <int> in, out;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!out.empty()){
        in.push(out.top());
        out.pop();
        }
        out.push(x);
        while(!in.empty()){
            out.push(in.top());
            in.pop();
        }
    }
    
    int pop() {
        int t = out.top();
        out.pop();
        return t;
        
    }
    
    int peek() {

        return out.top();
    }
    
    bool empty() {
        if(!out.empty())
        return false;
        else
        return true;
        
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */