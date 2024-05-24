class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size()-1;
        int l=0;
        int r=n;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)r=mid-1;
            else l=mid+1;
        }
        return -1;
    }
};