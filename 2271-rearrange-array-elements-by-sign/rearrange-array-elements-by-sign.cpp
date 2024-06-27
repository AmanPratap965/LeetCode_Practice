class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int negInd=1;
        int posInd=0;
        for(int i=0;i<n;i++){
                if(nums[i]<0){
                        ans[negInd]=nums[i];
                        negInd+=2;
                }else{
                    ans[posInd]=nums[i];
                    posInd+=2;
                }
        }
        return ans;
    }
};