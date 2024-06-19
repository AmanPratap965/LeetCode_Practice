class Solution {
public:
    int fn(int ind,int prevInd,vector<int>&nums,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        int take=0;
        if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            take=1+fn(ind+1,ind,nums,n,dp);
        }
        int notTake=0+fn(ind+1,prevInd,nums,n,dp);
        return dp[ind][prevInd+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return fn(0,-1,nums,n,dp);
        // for(int prevInd=0;prevInd<=n;prevInd++)dp[n][prevInd]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int prevInd=ind-1;prevInd>=-1;prevInd--){
                 int take=0;
                    
                    if(prevInd==-1 || nums[ind]>nums[prevInd]){
                        take=1+dp[ind+1][ind+1];
                    }
                    int notTake=0+dp[ind+1][prevInd+1];
                     dp[ind][prevInd+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
};