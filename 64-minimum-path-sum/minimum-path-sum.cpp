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
    int fn1(int row,int col,vector<vector<int>>&grid,int m,int n,vector<vector<int>>&dp){
        // if(row==0 && col==0)return grid[row][col];
        // if(row<0 || col<0)return mod;
        dp[0][0]=grid[0][0];
        // if(m==1 && n==1)return dp[0][0];
        for(int i=0;i<m;i++){
                int up=mod,left=mod;
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
             if(i>0)   up=grid[i][j]+dp[i-1][j];
              if(j>0)  left=grid[i][j]+dp[i][j-1];
                dp[i][j]=min(up,left);
            }
        }
        return dp[row][col];

        // if(dp[row][col]!=-1)return dp[row][col];
        // up=grid[row][col]+fn(row-1,col,grid,m,n,dp);
        // left=grid[row][col]+fn(row,col-1,grid,m,n,dp);
        // return dp[row][col]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn1(m-1,n-1,grid,m,n,dp);
    }
};