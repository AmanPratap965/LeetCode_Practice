class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int ind,int n){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        //non-pick
        solve(nums,ans,temp,ind+1,n);
        //pick
        temp.push_back(nums[ind]);
        solve(nums,ans,temp,ind+1,n);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(nums,ans,ds,0,nums.size());
        return ans;
    }
};