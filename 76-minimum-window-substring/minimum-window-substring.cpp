class Solution {
public:
    string minWindow(string s, string t) {
          if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        int l=0,r=0,n=s.size(),sindex=-1,cnt=0;
        // unordered_map<char,int>mp;//{char,freq}
        int mp[256]={0};
        int minlen=1e9+7;
        for(int i=0;i<t.size();i++)mp[t[i]]++;
        while(r<n){
            if(mp[s[r]]>0)cnt++;
            mp[s[r]]--;
            while(cnt==t.size()){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    sindex=l;
                }

                mp[s[l]]++;
                if(mp[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        return sindex==-1?"":s.substr(sindex,minlen);
    }
};