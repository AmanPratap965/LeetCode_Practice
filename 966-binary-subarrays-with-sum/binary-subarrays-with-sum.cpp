class Solution {
public:
    int subarrayWithSumGoal(vector<int>&nums,int goal){
        if(goal<0)return 0;
         int n=nums.size();
        int l=0,r=0,cnt=0;
        int size=0;
        while(r<n){
            size+=nums[r];
            while(size>goal){
                size-=nums[l];  
                l++;
            }
           cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return subarrayWithSumGoal(nums,goal)-subarrayWithSumGoal(nums,goal-1);
    }
};