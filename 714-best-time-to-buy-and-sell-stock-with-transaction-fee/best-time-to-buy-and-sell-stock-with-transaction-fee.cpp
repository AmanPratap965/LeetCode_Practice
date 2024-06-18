class Solution {
public:
     int fn(int ind,int buy,int fee,vector<int>prices,int n,vector<vector<int>>&dp){
        if(ind>=n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            int take=-prices[ind]-fee+fn(ind+1,0,fee,prices,n,dp);
            int notTake=0+fn(ind+1,1,fee,prices,n,dp);
            return dp[ind][buy]=max(take,notTake);
        }else{
            int take=prices[ind]+fn(ind+1,1,fee,prices,n,dp);
            int notTake=fn(ind+1,0,fee,prices,n,dp);
            return dp[ind][buy]=max(take,notTake);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        // return fn(0,1,fee,prices,prices.size(),dp);
        vector<int>after(2,0);
        vector<int>curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                     if(buy){
                        int take=-prices[ind]-fee+after[0];
                        int notTake=0+after[1];
                         curr[buy]=max(take,notTake);
                    }else{
                        int take=prices[ind]+after[1];
                        int notTake=after[0];
                         curr[buy]=max(take,notTake);
                    }
            }
            after = curr;
        }
        return after[1];
    }
};