class Solution {
public:
bool fn(int n,int sum,vector<int>&arr){
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        prev[0]=curr[0]=true;
        if(sum==arr[0])
        prev[arr[0]]=true;
        
        for(int i=0;i<n;i++)curr[0]=true;
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                
                bool take=0;
                if(arr[i]<=target)take=prev[target-arr[i]];
                bool notTake=prev[target];
                curr[target]=take || notTake;
            }
            prev=curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        if(n==1)return false;
        for(auto it:nums)sum+=it;
        // vector<vector<bool>>dp(nums.size(),vector<bool>(sum+1,0));
        if(sum%2==0)sum=sum/2;
        else return false;
        return fn(n,sum,nums);
    }
};