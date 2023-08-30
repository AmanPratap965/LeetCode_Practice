class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        //create a vector containing all 1's
        for(int i=0;i<n;i++){
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};