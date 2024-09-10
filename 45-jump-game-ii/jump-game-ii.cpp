class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,l=0,r=0;
        int n=nums.size();
        while(r<n-1){
            int farthest=0;
            for(int ind=l;ind<=r;ind++){
                farthest=max(farthest,ind+nums[ind]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};