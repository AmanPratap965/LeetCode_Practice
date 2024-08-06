class Solution {
public:
    int solve(int ind,vector<int>&nums,int target){
        if(ind==0){
            if(target==0 && nums[0]==0)return 2;
            if(target==0 || target==nums[0])return 1;
            
            return 0;
        }
        int take=0;
        if(target-nums[ind]>=0) take=solve(ind-1,nums,target-nums[ind]);
        int notTake=solve(ind-1,nums,target);
        return take+notTake;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totSum=0;
        for(auto it:nums)totSum+=it;
        if(totSum-target<0 || (totSum-target)%2==1)return 0;
        int s1=(totSum-target)/2;
        return solve(n-1,nums,s1);
    }
};