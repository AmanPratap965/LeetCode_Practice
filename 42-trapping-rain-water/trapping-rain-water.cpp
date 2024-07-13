class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pref(n);
        vector<int>suff(n);
        int sum=0;
        // prefix Sum
        for(int i=0;i<n;i++){
                sum=max(height[i],sum);
                pref[i]=sum;
        }
        // suffix sum
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum=max(sum,height[i]);
            suff[i]=sum;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(pref[i],suff[i])-height[i];
        }
        return ans;
    }
};