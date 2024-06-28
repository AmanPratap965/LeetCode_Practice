class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==(n/3)+1){
                ans.push_back(nums[i]);
            }
            if(ans.size()==2)break;
        }
        return ans;
    }
};