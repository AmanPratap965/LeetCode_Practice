class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp1,mp2;//mp1-->{node,col} || mp2->{col,occurences}
         vector<int>ans;
        for(auto &it:queries){
            int u=it[0];
            int v=it[1];
            if(mp1.find(u)!=mp1.end()){
                int col=mp1[u];
                mp2[col]--;
                if(mp2[col]==0)mp2.erase(col);
            }
            mp1[u]=v;
            mp2[v]++;
            ans.push_back(mp2.size());
        }
        return ans;
    }
};