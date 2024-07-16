class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int odd=0;
        int l=0,r=0;
        int cnt=0;
        int anscount=0;
        while(r<n){
            if(nums[r]&1){odd++;cnt=0;}
            while(odd==k){
               if(nums[l]&1)odd--;
                cnt++;
               l++;
            }
            anscount+=cnt;
            r++;
        }
        return anscount;
    }
};