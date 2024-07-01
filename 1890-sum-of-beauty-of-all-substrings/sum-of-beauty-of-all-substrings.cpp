class Solution {
public:
    int beauty(vector<int>&mp){
        int mf=-1;int lf=1e9;
        for(int i=0;i<26;i++){
            mf=max(mf,mp[i]);
            if(mp[i]>=1){
                lf=min(lf,mp[i]);
            }
        }
        return mf-lf;
    }
    int beautySum(string s) {
        int n=s.size();
        int res=0;
        for(int i=0;i<n;i++){
            vector<int>mp(26,0);
            for(int j=i;j<n;j++){
                mp[s[j]-'a']++;
                res+=beauty(mp);
            }
        }
        return res;
    }
};