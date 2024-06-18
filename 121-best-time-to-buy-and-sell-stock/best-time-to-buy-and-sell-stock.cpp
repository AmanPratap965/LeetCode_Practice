class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff=0;
        int mini=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++){
            if(mini>prices[i]){
                mini=prices[i];
            }
                diff=max(diff,prices[i]-mini);
        }
        return diff;
    }
};