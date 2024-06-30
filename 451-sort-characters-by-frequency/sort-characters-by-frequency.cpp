class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp1;
        multimap<int,char,greater<int>>mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]++;
        }
        for(auto it:mp1){
            mp2.insert({it.second,it.first});
        }
        string ans="";
        for(auto it:mp2){
            string s="";
            int x=it.first;
            while(x){
                s+=it.second;
                x--;
            }
            ans+=s;
        }
        return ans;
    }
};