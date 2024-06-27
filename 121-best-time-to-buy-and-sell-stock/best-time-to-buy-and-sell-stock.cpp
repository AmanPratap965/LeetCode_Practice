class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int smallest=prices[0];
        for(int i=0;i<n;i++){
                int diff=prices[i]-smallest;
                smallest=min(smallest,prices[i]);
                maxProfit=max(maxProfit,diff);
        }
        return maxProfit;
    }
};