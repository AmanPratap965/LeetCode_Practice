class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         int n=nums.size();
         unordered_set<int>mp;
        //  if(nums.size()==0)return 0;/
         for(int i=0;i<n;i++){
            mp.insert(nums[i]);
         }
        int maxlen=0;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int len=0;
            if(mp.find(x-1)==mp.end()){
            while(mp.find(x)!=mp.end()){
                len++;
                x=x+1;
                maxlen=max(maxlen,len);
            }
            }
        }
        return maxlen;
    }
};