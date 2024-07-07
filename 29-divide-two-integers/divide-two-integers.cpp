class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==(1<<31) && divisor==-1 )return INT_MAX;
        bool sign=(dividend>=0 == divisor>=0)?true:false;
        long long n=abs(dividend);
        long long d=abs(divisor);
        long long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>(d<<(cnt+1))){
                cnt++;
               
            }
             ans+=(1<<cnt);
            n-=(d<<cnt);
        }
        if(sign){
            if(ans==(1<<31))return INT_MAX;
            else return ans;
        }
        else return -1*ans;
    }
};