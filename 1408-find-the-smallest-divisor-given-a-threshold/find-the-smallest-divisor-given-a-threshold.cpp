class Solution {
public:
    int solve(int mid,vector<int>nums){
        int totalSum=0;
        for(auto it:nums){
            totalSum+=it/mid;
            if(it%mid!=0){
                totalSum+=1;
            }
        }
        return totalSum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int r=0;
        int l=1;
        for(auto it:nums)r=max(r,it);
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=solve(mid,nums);
            if(sum<=threshold){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};