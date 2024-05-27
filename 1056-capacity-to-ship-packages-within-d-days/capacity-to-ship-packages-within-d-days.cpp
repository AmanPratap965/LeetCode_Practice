class Solution {
public:
    int solve(int maxSum,vector<int>&weights){
        int ans=0;
        int sum=0;
        for(auto it:weights){
            // if(it>maxSum)return -1;
                if(sum+it<=maxSum)sum+=it;
                else{
                    ans++;
                    sum=it;
                }
        }
        if(sum<=maxSum)ans++;
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=0;
        for(int i=0;i<weights.size();i++){
            r+=weights[i];
            l=max(l,weights[i]);
        }
        int ans=0;
        while(l<=r){
                int mid=l+(r-l)/2;
                int totalWeightDays=solve(mid,weights);
                // if(totalWeightDays==days){
                //     ans=mid;return ans;
                // }
                if(totalWeightDays==-1){
                    l=mid+1;
                    continue;
                }
                cout<<"mid "<<mid <<"totalDays "<<totalWeightDays<<endl;
                if(totalWeightDays<=days){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
        }
        return ans;
    }
};