class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     
        int n=nums.size();
        vector<int>ans;
        int cnt1=0;int ele1=0,cnt2=0,ele2=0;
        for(int i=0;i<nums.size();i++){
           if(cnt1==0 && nums[i]!=ele2){cnt1++;ele1=nums[i];}
           else if(cnt2==0 && nums[i]!=ele1){cnt2++;ele2=nums[i];}
           else if(ele1==nums[i])cnt1++;
           else if(ele2==nums[i])cnt2++;
           else{cnt1--;cnt2--;}
        }
        int min=(n/3)+1;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele1)cnt1++;
            else if(nums[i]==ele2)cnt2++;
        }
        if(cnt1>=min)ans.push_back(ele1);
        if(cnt2>=min)ans.push_back(ele2);
        return ans;
        // return {ele1,ele2};
    }
};