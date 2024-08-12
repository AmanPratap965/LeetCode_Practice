class Solution {
public:
    bool solve(int ind,string&s,int cnt,vector<vector<bool>>&dp){
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
        vector<vector<bool>>dp(s.size()+1,vector<bool>(s.size()+1,0));
        // return solve(0,s,0,dp);
        int cnt=0;
        int n=s.size();
        //base case
        for(int i=0;i<n;i++){
            dp[n][i]=(i==0);
        }
            for(int ind=n-1;ind>=0;ind--){
                for(int cnt=0;cnt<=n;cnt++){
                    if(s[ind]=='(') dp[ind][cnt]=solve(ind+1,s,cnt+1,dp);
                    else if(s[ind]==')') dp[ind][cnt]=solve(ind+1,s,cnt-1,dp);
                    else {
                        dp[ind][cnt]= (solve(ind+1,s,cnt-1,dp))|| (solve(ind+1,s,cnt,dp)) || (solve(ind+1,s,cnt+1,dp));
                    }
                }
            }

            return dp[0][0];
    }

};