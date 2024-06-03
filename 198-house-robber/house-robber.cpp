class Solution {
public:
    int fn(int n,vector<int>&nums,vector<int>&dp){
    if(n==0)return nums[0];
    if(n<0)return 0;
    // if(n==1)return max(nums[0],nums[1]);   
    //not-pick
    if(dp[n]!=-1)return dp[n];
    int notPick=fn(n-1,nums,dp);
    //pick
    int pick=nums[n]+fn(n-2,nums,dp);
    
    return dp[n]=max(pick,notPick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        // nums.push_back(0);
        vector<int>dp(n,-1);
        return fn(n-1,nums,dp);
    }
};