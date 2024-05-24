class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        //so we have to calculate the upper bound of the value
        int l=0;
        int r=arr.size()-1;
        int ans=-1;
        if(target>arr[r])return r+1;
        while(l<=r){
            int mid=l+(r-l)/2;
           if(arr[mid]>=target){
            ans=mid;
            r=mid-1;
           }else{
            l=mid+1;
           }
        }
        return ans;
    }
};