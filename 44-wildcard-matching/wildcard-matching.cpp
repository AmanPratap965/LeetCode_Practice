class Solution {
public:
    bool fn(int i,int j,string s, string p){
        if(i==0 && j==0)return true;
        if(i==0 && j>0)return false;
        if(i>0 && j==0 ){
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*')return false;
            }
            return true;
        }

        //match
        if(s[i-1]==p[j-1] || p[j-1]=='?')return fn(i-1,j-1,s,p);
        if(p[j-1]=='*'){
            return fn(i-1,j,s,p) || fn(i,j-1,s,p);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // return fn(n,m,s,p);
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=true;
        for(int i=1;i<=m && p[i-1]=='*';i++){
            bool fl=true;
           
            dp[0][i]= fl;
        }

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                     //match
                    if(s[i-1]==p[j-1] || p[j-1]=='?')dp[i][j]= dp[i-1][j-1];
                   else if(p[j-1]=='*'){
                        dp[i][j]=dp[i-1][j] || dp[i][j-1];
                    }

                    else dp[i][j]= false;
                }
            }
            return dp[n][m];

    }
};