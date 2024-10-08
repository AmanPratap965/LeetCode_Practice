class StockSpanner {
    stack<pair<int,int>>st;//pair of stack {price,span}
public:
    StockSpanner() {
      
    }
    
    int next(int price) {
        int ans=1;
      while(!st.empty() && st.top().first<=price){
            ans+=st.top().second;
            st.pop();
      }
      st.push({price,ans});
      return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */