class Solution {
public:
    int fn(int ind,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(cap==0)return 0;
        if(ind==n)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy){
            int bought=-prices[ind]+fn(ind+1,0,cap,prices,n,dp);
            int notBought=0+fn(ind+1,1,cap,prices,n,dp);
            return dp[ind][buy][cap]=max(bought,notBought);
        }
        else{
            int sold=prices[ind]+fn(ind+1,1,cap-1,prices,n,dp);
            int notSold=0+fn(ind+1,0,cap,prices,n,dp);
            return dp[ind][buy][cap]=max(sold,notSold);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // return fn(0,1,2,prices,n,dp);

        for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
                        if(buy){
                                int bought=-prices[ind]+dp[ind+1][0][cap];
                                int notBought=0+dp[ind+1][1][cap];
                                 dp[ind][buy][cap]=max(bought,notBought);
                            }
                            else{
                                int sold=prices[ind]+dp[ind+1][1][cap-1];
                                int notSold=0+dp[ind+1][0][cap];
                                 dp[ind][buy][cap]=max(sold,notSold);
                            }
                    }
                }
        }
        return dp[0][1][2];
    }
};