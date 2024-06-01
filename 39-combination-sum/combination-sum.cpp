class Solution {
public:
    void solve(int ind,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans,int target,int sum){
        if(ind==nums.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }
        if(sum>target)return;
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        //not-pick
        solve(ind+1,nums,temp,ans,target,sum);
        //pick
        temp.push_back(nums[ind]);
        solve(ind,nums,temp,ans,target,sum+nums[ind]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,temp,ans,target,0);
        return ans;
    }
};