class Solution {
public:
    void solve(int ind,vector<int>nums,vector<vector<int>>&ans,int n){
        if(ind==n){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            // temp.push_back(nums[ind]);
            solve(ind+1,nums,ans,n);
            // temp.pop_back();
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        solve(0,nums,ans,n);
        return ans;
    }
};