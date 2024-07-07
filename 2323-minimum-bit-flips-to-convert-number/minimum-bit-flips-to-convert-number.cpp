class Solution {
public:
    int minBitFlips(int start, int goal) {
        if(start==goal)return 0;
        int x=start^goal;int cnt=0;
        while(x){
            x=x&(x-1);cnt++;
        }
        return cnt;
    }
};