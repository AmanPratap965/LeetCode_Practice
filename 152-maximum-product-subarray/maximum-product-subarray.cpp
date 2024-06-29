class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        double pref=1;double suff=1;
        double maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(pref==0)pref=1;
            if(suff==0)suff=1;
            pref=pref*(double)nums[i];
            suff=suff*(double)nums[n-1-i];
            maxi=max(maxi,max(pref,suff));
        }
        return maxi;
    }
};