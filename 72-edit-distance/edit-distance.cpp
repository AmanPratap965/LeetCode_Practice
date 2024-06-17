class Solution {
public:
    int fn(int i,int j,string word1,string &word2){
        if(i==0)return j;
        if(j==0)return i;
        if(word1[i-1]==word2[j-1])return fn(i-1,j-1,word1,word2);
        return 1+min(fn(i-1,j,word1,word2),min(fn(i,j-1,word1,word2),fn(i-1,j-1,word1,word2)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return fn(n,m,word1,word2);
        for(int j=0;j<=m;j++)dp[0][j]=j;
        for(int i=0;i<=n;i++)dp[i][0]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }
};