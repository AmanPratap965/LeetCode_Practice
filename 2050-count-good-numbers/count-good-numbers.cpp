class Solution {
public:
    int mod=1e9+7;
    long long power(long long base,long long n){
        long long ans=1;
        long long nn=n;
        while(nn>0){
            if(nn%2==1){
                ans=(ans*base)%mod;
                nn--;
            }else{
                base=(base*base)%mod;
                nn=nn/2;
            }
        }
        return ans%mod;
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        
        //total even numbers -2,4,6,8,0 -->5
        //total prime nos.---->2,3,5,7--->4
        //sum---->5^even*4^odd
        long long sum=power(5,even);
        sum*=power(4,odd);
        return sum%mod;
    }
};