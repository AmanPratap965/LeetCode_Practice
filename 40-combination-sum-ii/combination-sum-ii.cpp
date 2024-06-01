class Solution {
public:
void solve(int index,vector<int>&candidates, vector<vector<int>>&ans, int target,vector<int>smallsum){
        //base case
      
        if(target==0){
            // sort(smallsum.begin(),smallsum.end());
            ans.push_back(smallsum);
            return;
        }
        if(target<0){
            return;
        }
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target){
                    break;
            }
            //pick
        smallsum.push_back(candidates[i]);
        target-=candidates[i];
        
        
        solve(i+1,candidates,ans,target,smallsum);
        smallsum.pop_back();
        target+=candidates[i];
        }
        
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>smallsum;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,ans,target,smallsum);
        
        return ans;
    }
};