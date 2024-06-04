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
 int solve1(int row,int col,vector<vector<int>>&mat,int n,int m,vector<vector<int>>&dp){
//     if(row>=0 && col>=0 && mat[row][col]==1)return 0;
//   if(row==0 && col==0)return 1;
//   if(row<0 || col<0)return 0;

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){

                    if(mat[i][j]==1){dp[i][j]=0;continue;}
                    if(i==0 && j==0){
                        dp[0][0]=1;
                        continue;
                    }
                    int up=0,left=0;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=(up+left)%mod;
                }
            }
        return dp[row][col];
}
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n =mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
           return solve1(n-1,m-1,mat,n,m,dp);
    }
};