class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        int j=1;
        for(int i=1;i<n;i++){
            if(nums[i-1]!=nums[i]){
                nums[j++]=nums[i];
            }
        }
        return j;
    }
};