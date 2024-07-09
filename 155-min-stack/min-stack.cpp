class MinStack {
    stack<long long>st;
    long long mini;
public:
    MinStack() {
        while(st.empty()==false)st.pop();
        mini=INT_MAX; 
    }
    
    void push(int value) {
        long long val=value;
        if(st.empty()){
            mini=val;
            st.push(val);
        }else{
            if(val<mini){
                    st.push(2*val-mini);
                    mini=val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())return ;
        long long el=st.top();
        st.pop();
        if(el<mini){
            mini=2*mini-el;
        }   
    }
    
    int top() {
        long val=st.top();
        if(val<mini){
            return (int)mini;
        }
        return (int)val;

    }
    
    int getMin() {
        return (int)mini;
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