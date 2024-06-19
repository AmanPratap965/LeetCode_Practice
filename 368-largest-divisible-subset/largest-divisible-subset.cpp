class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        sort(nums.begin(),nums.end());
        vector<int>parent(n);
        int lastInd=0;int maxi=1;
        for(int ind=0;ind<n;ind++){
            parent[ind]=ind;
                for(int prevInd=0;prevInd<ind;prevInd++){
                    if(nums[ind]%nums[prevInd]==0  && dp[ind]<1+dp[prevInd]){
                        dp[ind]=1+dp[prevInd];
                        parent[ind]=prevInd;
                    }
                }
                if(maxi<dp[ind]){
                    maxi=dp[ind];
                    lastInd=ind;
                }
        }
        
        vector<int>ans;
        ans.push_back(nums[lastInd]);
        while(parent[lastInd]!=lastInd){
            lastInd=parent[lastInd];
            ans.push_back(nums[lastInd]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};