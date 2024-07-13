class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        const int MOD=1e9+7;
        int n=arr.size();

        vector<int> nsl(arr.size());
        vector<int> nsr(arr.size());

        stack<int> st;
        for(int i=0;i<n;++i){
            if(st.empty()){
                nsl[i]=-1;
                st.push(i);
                continue;
            }
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nsl[i]=st.empty()?-1:st.top();
            st.push(i);
        }

        st=stack<int>();
        
        for(int i=n-1;i>=0;--i){
            if(st.empty()){
                nsr[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                nsr[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        
        for(int i=0;i<n;++i){
            long long l=i-nsl[i];
            long long r=nsr[i]-i;
            long long m=(l%MOD * r%MOD) % MOD;
            ans=(ans + (arr[i] * m) % MOD) % MOD;
        }

        return ans;
    }
};