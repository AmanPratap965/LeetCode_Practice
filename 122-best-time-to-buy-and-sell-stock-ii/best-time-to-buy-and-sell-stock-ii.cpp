class Solution {
public:
    int fn(int ind,int buy,vector<int>prices,int n,vector<vector<int>>&dp){
        if(ind==n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            int take=-prices[ind]+fn(ind+1,0,prices,n,dp);
            int notTake=0+fn(ind+1,1,prices,n,dp);
            return dp[ind][buy]=max(take,notTake);
        }else{
            int take=prices[ind]+fn(ind+1,1,prices,n,dp);
            int notTake=fn(ind+1,0,prices,n,dp);
            return dp[ind][buy]=max(take,notTake);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        // return fn(0,1,prices,prices.size(),dp);
        int n=prices.size();
        dp[n][0]=dp[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                        int take=-prices[ind]+dp[ind+1][0];
                        int notTake=0+dp[ind+1][1];
                         dp[ind][buy]=max(take,notTake);
                    }else{
                        int take=prices[ind]+dp[ind+1][1];
                        int notTake=dp[ind+1][0];
                         dp[ind][buy]=max(take,notTake);
                    }
            }
        }
        return dp[0][1];
    }
};