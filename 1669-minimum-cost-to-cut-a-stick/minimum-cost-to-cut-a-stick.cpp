class Solution {
public:
    int fn(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j)return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=i;k<=j;k++){
            int cost=(cuts[j+1]-cuts[i-1])+fn(i,k-1,cuts,dp)+fn(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        // return fn(1,c,cuts,dp);
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                 int mini=INT_MAX;
                    if(i>j)continue;
                    for(int k=i;k<=j;k++){
                        int cost=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
                        mini=min(mini,cost);
                    }
                     dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};