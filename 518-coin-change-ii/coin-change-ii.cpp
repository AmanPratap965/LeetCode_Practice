class Solution {
public:
int fn(int ind,int target,vector<int>&coins,vector<vector<int>>dp){
    if(ind==0){
        if(target%coins[0]==0)return 1;
        else return 0;
    }
    // if(target==0)return 1;
    if(dp[ind][target]!=-1)return dp[ind][target];
    int pick=0;
    if(target>=coins[ind]){
        pick=fn(ind,target-coins[ind],coins,dp);
    }
    int notPick=fn(ind-1,target,coins,dp);
    return dp[ind][target]=pick+notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // return fn(n-1,amount,coins,dp);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
            else dp[0][i]=0;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int pick=0;
                if(target>=coins[ind]){
                    pick=dp[ind][target-coins[ind]];
                }
                int notPick=dp[ind-1][target];
                 dp[ind][target]=pick+notPick;
            }
        }
        return dp[n-1][amount];
    }
};