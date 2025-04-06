class Solution {
public:
    int reverse(int x){
        int n=0;
        while(x){
            int lastDigit = x%10;
            if(n>INT_MAX/10)return -1;
            n = lastDigit + n*10;
            x=x/10;
        }
        return n;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        int n=reverse(x);
        return n == x ?  true: false;
    }
};