class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int cnt=0;
        int maxi=0;
        for(auto it:st){
                if(st.find(it-1)==st.end()){
                    cnt=1;
                    int x=it;
                    while(st.find(x+1)!=st.end()){
                        x=x+1;
                        cnt++;
                    }
                    maxi=max(maxi,cnt);
                }
        }
        return maxi;
    }
};