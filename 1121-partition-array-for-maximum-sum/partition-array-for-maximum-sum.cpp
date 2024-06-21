class Solution {
public:
    int fn(int ind,vector<int>&arr,int k,int n,vector<int>&dp){
        if(ind==n)return 0;
        int len=0;
        int maxi=0;
        int maxSum=0;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=ind;i<min(n,ind+k);i++){
                len++;
                maxi=max(maxi,arr[i]);
                int sum=len*maxi+fn(i+1,arr,k,n,dp);
                maxSum=max(maxSum,sum);
        }
        return dp[ind]=maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return fn(0,arr,k,n,dp);
    }
};