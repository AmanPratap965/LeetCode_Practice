class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        //next smaller left
        vector<int>NSL(n);
        for(int i=0;i<n;i++){
            while(!st.empty() &&  heights[st.top()]>=heights[i])st.pop();
            NSL[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        //next smaller right
        st=stack<int>();
        vector<int>NSR(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])st.pop();
            NSR[i]=st.empty()?n:st.top();
            st.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
                int ls=i-NSL[i];
                int rs=NSR[i]-i;
                int width=rs+ls-1;
                int area=heights[i]*width;//height* width
                maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};