class Solution {
public:
    int mySqrt(int x) {
        long long int l=0;
        long long int r=x/2;
        long long int ans=0;
        int mod=1e9+7;
        if(x==1)return 1;
        while(l<=r){
            long long int mid=l+(r-l)/2;
            if((mid*mid)==x){
                return mid;
            }else if(mid*mid>x){
                r=mid-1;
            }else{
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
    }
};