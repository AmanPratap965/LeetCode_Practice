class Solution {
public:
    int mod=2e9;
    int solve(int row,int col,vector<vector<int>>&mat,int n,int m,vector<vector<int>>&dp){
    if(row>=0 && col>=0 && mat[row][col]==1)return 0;
  if(row==0 && col==0)return 1;
  if(row<0 || col<0)return 0;
            if(dp[row][col]!=-1)return dp[row][col];
        int up=solve(row-1,col,mat,n,m,dp);
        int left=solve(row,col-1,mat,n,m,dp);
          return dp[row][col]=(up+left)%mod;
}
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n =mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
           return solve(n-1,m-1,mat,n,m,dp);
    }
};