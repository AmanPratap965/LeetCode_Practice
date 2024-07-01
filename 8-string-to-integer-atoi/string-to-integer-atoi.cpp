class Solution {
public:
    int mod=1e9+7;
    int myAtoi(string s) {
        long ans=0;
        int n=s.size();
        int flag=1;
        int j=0;
        while(s[j]==' '){
            j++;
        }
        if(s[j]=='+')j++;
        else if(s[j]=='-'){
            flag=-1;
            j++;
        }
        for(int i=j;i<n;i++){
                 if(s[i]>='0' && s[i]<='9'){
                    ans=(ans*10)+(s[i]-'0');
                    if(flag==1 && ans>INT_MAX)return INT_MAX;
                    if(flag==-1 && ans>INT_MAX)return INT_MIN;

                 }
                else{
                    break;
                }
        }
        return ans*flag;
    }
};