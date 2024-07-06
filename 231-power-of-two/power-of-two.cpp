class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt=1;
        for(int i=0;i<=30;i++){
                if(cnt==n)return true;
                if(cnt<INT_MAX/2)
                cnt*=2;
        }
        return false;
    }
};