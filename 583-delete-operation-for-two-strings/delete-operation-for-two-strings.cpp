class Solution {
public:
int longestPalindromeSubseq(string s1,string s2) {
       
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));


        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                int match=0;
                if(s1[ind1-1]==s2[ind2-1]){
                        dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
                }
                else dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);

            }

        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
            int n=word1.length();int m=word2.length();
            int ans=longestPalindromeSubseq(word1,word2);
            return (m+n)-2*ans;
    }
};