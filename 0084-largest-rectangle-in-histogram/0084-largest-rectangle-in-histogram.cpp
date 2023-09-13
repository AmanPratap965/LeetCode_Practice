class Solution {
public:
    vector<int>nextSmallerElement(vector<int>&arr,int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){st.pop();}
            // ans.push_back(st.top());
            ans[i]=(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int>prevSmallerElement(vector<int>&arr,int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i=0;i<n;i++){
            int curr=arr[i];
            while(st.top()!=-1 && arr[st.top()]>=curr){st.pop();}
            ans[i]=(st.top());
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int>next(n);
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }

};