class Solution {
public:
    int fn(int ind,int target,vector<int>&coins,vector<vector<int>>dp){
        if(ind==0){
            if(target%coins[0]==0)return target/coins[0];
            else return 1e9+7;
        }
        int pick=INT_MAX;
        if(dp[ind][target]!=-1)return dp[ind][target];
        if(target>=coins[ind]){
                pick=1+fn(ind,target-coins[ind],coins,dp);
        }
        int notPick=0+fn(ind-1,target,coins,dp);
        return dp[ind][target]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        //  int ans= fn(n-1,amount,coins,dp);
        //  if(ans==1e9+7)return -1;
        //  else return ans;
        //tabulation 
        //base case
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)dp[0][target]=target/coins[0];
            else dp[0][target]=1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                 int pick=INT_MAX;
                    // if(dp[ind][target]!=-1)return dp[ind][target];
                    if(target>=coins[ind]){
                            pick=1+dp[ind][target-coins[ind]];
                    }
                    int notPick=0+dp[ind-1][target];
                     dp[ind][target]=min(pick,notPick);
            }
        }
        return dp[n-1][amount]==1e9?-1:dp[n-1][amount];
    }
};