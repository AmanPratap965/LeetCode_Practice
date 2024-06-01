class Solution {
public:
    void solve(int ind,vector<int>temp,vector<vector<int>>&ans,int target,int k){
        if(ind==10){
            if(temp.size()==k && target==0)ans.push_back(temp);
            return;
        }
        if(target==0){
           if(temp.size()==k) ans.push_back(temp);
            return;
        }
        //pick 
        if(ind<=target){
        temp.push_back(ind);
        solve(ind+1,temp,ans,target-ind,k);
        temp.pop_back();
        }
        solve(ind+1,temp,ans,target,k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        
        vector<int>temp;
        solve(1,temp,ans,n,k);
        return ans;
    }
};