class Solution {
public:
    bool checkPossible(string s1,string s2){
        int n=s1.size();int m=s2.size();
        if(n!=m+1)return false;
        int i=0;int j=0;
        while(i<n){
            if(s1[i]==s2[j]){i++;j++;}
            else {i++;}

        }
        if(i==n && j==m)return true;
         return false;
    }
    bool static comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        sort(words.begin(),words.end(),comp);
        int maxi=1;
        for(int ind=0;ind<n;ind++){
            for(int prevInd=0;prevInd<=ind-1;prevInd++){
                if(checkPossible(words[ind],words[prevInd]) && dp[ind]<1+dp[prevInd]){

                        dp[ind]=1+dp[prevInd];
                }
            }
           maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};