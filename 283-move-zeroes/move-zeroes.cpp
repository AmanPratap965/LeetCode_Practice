class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n=nums.size();
       int j=-1;
       if(n==1)return;
       for(int i=0;i<n;i++){
        if(nums[i]==0 && j==-1){
           j=i;
        }else if(nums[i]!=0 && j!=-1){
            swap(nums[j++],nums[i]);
           
        }
       } 
    }
};