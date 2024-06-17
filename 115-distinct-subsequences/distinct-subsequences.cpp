class Solution {
public:
    int fn(int i,int j,string s,string t){
        if(j==0)return 1;
        if(i==0)return 0;
        if(s[i-1]==t[j-1])return fn(i-1,j-1,s,t)+fn(i-1,j,s,t);
         return fn(i-1,j,s,t);
    }
    int numDistinct(string s, string t) {
        long long n=s.size();
        long long m=t.size();
    //    return fn(n,m,s,t); 
            vector<vector<double>>dp(n+1,vector<double>(m+1,0));
            for(long long i=0;i<=n;i++)dp[i][0]=1;

            for(long long i=1;i<=n;i++){
                for(long long j=1;j<=m;j++){
                    if(s[i-1]==t[j-1])dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
                    else dp[i][j]= dp[i-1][j];
                }
            }
            return (int)dp[n][m];
            }
};