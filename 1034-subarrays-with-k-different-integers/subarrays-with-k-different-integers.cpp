class Solution {
public:
    int fn(vector<int>&nums,int k){
        int n=nums.size();
        int l=0,r=0;
        int ans=0;
        unordered_map<int,int>mp;//{integre,freq}
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fn(nums,k)-fn(nums,k-1);
    }
};