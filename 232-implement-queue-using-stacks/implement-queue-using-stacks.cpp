class MyQueue {
    stack<int>st1;
    stack<int>st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            //st1-->st2
            st2.push(st1.top());
            st1.pop();
        }
        //push(x) in st1
        st1.push(x);
        //transfer back st2-->st1
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }

    }
    
    int pop() {
        int x=st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.size()==0;
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