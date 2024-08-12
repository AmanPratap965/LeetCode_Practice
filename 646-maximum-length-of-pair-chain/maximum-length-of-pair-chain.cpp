class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int cnt=1;
        int endLine=pairs[0][1];
        for(int i=0;i<pairs.size();i++){
            if(endLine<pairs[i][0]){
                endLine=pairs[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};