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
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(0,s,0,dp);
        // int ans;
        // // stack<int>st;
        // int open=0;
        // int star=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='(' )open=1;
        //     else if(s[i]=='*')star=1;
        //     else if(s[i]==')'){
        //         if(open)open--;
        //         else if(star)star--;
        //         else return false;
        //     }
        // }
        // while(open && star){
        //     star--;
        //     open--;
        // }
        // if(open)return false;
        // return true;
    }

};