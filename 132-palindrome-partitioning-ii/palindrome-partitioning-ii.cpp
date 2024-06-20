class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int dfs(int i,int j,string s,vector<int> &dp){
        if(i >= j or isPalindrome(s,i,j)) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int count = 1+dfs(k+1,j,s,dp);
                ans = min(ans,count);
            }
            
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return dfs(0,n-1,s,dp);
    }
    // bool palindrome(int s,int e,string str){
    //     while(s<e){
    //         if(str[s]!=str[e])return false;
    //         s++;e--;
    //     }
    //     return true;
    // }
    // int fn(int i,string s,int n,vector<int>&dp){
    //     if(i==n)return 0;
    //     int minCost=INT_MAX;
    //     if(dp[i]!=-1)return dp[i];
    //     for(int j=i;j<n;j++){
            
    //         if(palindrome(i,j,s)){
    //           int  cost= fn(j+1,s,n,dp);
    //           if(j!=n-1)cost++;
    //           minCost=min(minCost,cost);
    //         }
    //     }
    //     return dp[i]=minCost;
    // }
    // int minCut(string s) {
    //         int n=s.size();
    //         vector<long>dp(n+1,0);
    //         // return fn(0,s,n,dp);
    //         for(int i=n-1;i>=0;i--){
    //             int minCost=INT_MAX;
    //             for(int j=i;j<n;j++){
    //                 if(palindrome(i,j,s)){
    //                 int  cost= 1+dp[j+1];
    //                 minCost=min(minCost,cost);
    //                 }
    //             }
    //              dp[i]=minCost;
    //         }
    //         return dp[0]-1;
    // }
};