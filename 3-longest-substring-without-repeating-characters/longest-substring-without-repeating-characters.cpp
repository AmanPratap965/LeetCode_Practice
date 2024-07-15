class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int l=0,r=0;
        int n=s.size();
       vector<int>hash(256,-1);//{char,location}
        //filling up location where they belong
        
        while(r<n){
            if(hash[s[r]]!=-1){
               if(hash[s[r]]>=l)l=hash[s[r]]+1;
                
            }
            maxlen=max(maxlen,r-l+1);
                hash[s[r]]=r;
                r++;
        }
        return maxlen;
    }
};