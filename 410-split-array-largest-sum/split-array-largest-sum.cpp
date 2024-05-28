class Solution {
public:
    bool solve(int sumAllowed,vector<int>&nums,int totalSubarrays){
        int sum=0;
        int subarrays=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=sumAllowed){
                sum+=nums[i];
            }else{
                sum=nums[i];
                subarrays++;
            }
        }
        if(subarrays>totalSubarrays)return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        //so in this question our range gonna be (total students accommodated in a sum)
        for(auto it:nums){
            l=max(l,it);r+=it;
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(solve(mid,nums,k)){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};