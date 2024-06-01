class Solution {
public:
    void solve(vector<int>&nums,vector<int>temp,vector<vector<int>>&ans,vector<int>&freq,int n){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        //selectin all the elements other then index
        // freq[ind]=1;
        for(int i=0;i<n;i++){
            if(freq[i]==0){
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(nums,temp,ans,freq,n);
                freq[i]=0;
                temp.pop_back();
            }
        }
        // freq[ind]=0;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        //tracing the element with the help of freq array
        vector<int>freq(n,0);
        solve(nums,temp,ans,freq,n);
        return ans;
    }
};