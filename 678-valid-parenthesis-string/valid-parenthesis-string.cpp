class Solution {
public:
    bool solve(int ind,string&s,int cnt,vector<vector<int>>&dp){
        if(cnt<0)return false;
        if(ind==s.size())return dp[ind][cnt]=(cnt==0);
        if(dp[ind][cnt]!=-1)return dp[ind][cnt];
        if(s[ind]=='(')return dp[ind][cnt]=solve(ind+1,s,cnt+1,dp);
        else if(s[ind]==')')return dp[ind][cnt]=solve(ind+1,s,cnt-1,dp);
        else {
           
            return dp[ind][cnt]= (solve(ind+1,s,cnt-1,dp))|| (solve(ind+1,s,cnt,dp)) || (solve(ind+1,s,cnt+1,dp));
        }
    }
    bool checkValidString(string s) {
        int n=s.size();
        //top-down approach -(memoization)
        // vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        // return solve(0,s,0,dp);

        //bottom-up approach
        vector<vector<bool>>dp(n+1,vector<bool>(n+1,0));
        //base cases
        //when (ind==n) || other case will automatically handled by assigning zero to the dp
        dp[n][0]=true;
            // Bottom-up approach
    for(int ind = n-1; ind >= 0; ind--) {
        for(int cnt = 0; cnt <= n; cnt++) {
            if(s[ind] == '(') {
                if(cnt < n) {
                    dp[ind][cnt] = dp[ind+1][cnt+1];
                }
            } else if(s[ind] == ')') {
                if(cnt > 0) {
                    dp[ind][cnt] = dp[ind+1][cnt-1];
                }
            } else {
                dp[ind][cnt] = (cnt > 0 ? dp[ind+1][cnt-1] : false) || dp[ind+1][cnt] || (cnt < n ? dp[ind+1][cnt+1] : false);
            }
        }
    }
            return dp[0][0];
    }

};