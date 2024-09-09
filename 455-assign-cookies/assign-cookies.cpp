class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int count=0;
        while(i<s.size() && j<g.size()){
            if(s[i]>=g[j]){
                    count++;
                    j++;
                    i++;
            }else if(s[i]<g[j]){
                i++;
            }
        }
        return count;
    }
};