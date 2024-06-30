class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int>s1;
        unordered_map<int,int>s2;
        for(int i=0;i<s.size();i++){
                if(s1.find(s[i])!=s1.end()){
                    if(s1[s[i]]!=t[i])return false;
                }else if(s2.find(t[i])!=s2.end()){
                    if(s2[t[i]]!=s[i])return false;

                }
                 else{
                    s1[s[i]]=t[i];
                    s2[t[i]]=s[i];
                }           
        }
        return true;
    }
};