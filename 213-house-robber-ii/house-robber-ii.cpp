class Solution {
public:
    int fn(int n,vector<int>&nums){
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notPick=prev1;
            int curr=max(pick,notPick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>num1=nums;
        vector<int>num2=nums;
        num1.pop_back();
        int ans1=fn(num1.size(),num1);
        num2.erase(num2.begin());
        int ans2=fn(num2.size(),num2);
        return max(ans1,ans2);
    }
};