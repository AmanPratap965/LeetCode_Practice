class Solution {
public:
    int findPivot(vector<int>&nums){
        int l=0;    
        int r=nums.size()-1;    
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>=nums[0]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
    int binarySearch(vector<int>&arr,int l,int r,int target){
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target)return mid;
            else if(arr[mid]>target)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int pivot=findPivot(nums);
        int search1=binarySearch(nums,l,pivot-1,target);
        int search2=binarySearch(nums,pivot,r,target);
        if(search1!=-1)return search1;
        else if(search2!=-1)return search2;
        return -1;
    }
};