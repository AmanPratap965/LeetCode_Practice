class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(n!=t.size())return false;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp.find(t[i])==mp.end()){
                    
                    return false;
            }else{
                mp[t[i]]--;
                if(mp[t[i]]==0)mp.erase(t[i]);
            }
        }
        return true;
    }
};