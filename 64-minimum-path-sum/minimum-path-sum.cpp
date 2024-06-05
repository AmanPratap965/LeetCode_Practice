class Solution {
public:
    int mod=1e7;
    int fn(int row,int col,vector<vector<int>>&grid,int m,int n,vector<vector<int>>&dp){
        if(row==0 && col==0)return grid[row][col];
        if(row<0 || col<0)return mod;
        int up=mod,left=mod;
        if(dp[row][col]!=-1)return dp[row][col];
        up=grid[row][col]+fn(row-1,col,grid,m,n,dp);
        left=grid[row][col]+fn(row,col-1,grid,m,n,dp);
        return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(m-1,n-1,grid,m,n,dp);
    }
};