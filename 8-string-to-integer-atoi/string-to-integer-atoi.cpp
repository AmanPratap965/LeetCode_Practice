#include<string>
class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int flag=true;
        long ans=0;
        while(s[i]==' ')i++;
        if(s[i]=='-'){
            flag=false;
            i++;
        }
        else if(s[i]=='+'){
            flag=true;i++;
        }
        while(i<n){
            
             if(s[i]<='9' && s[i]>='0'){
                    ans=ans*10+(s[i]-'0');
                    
                        if(flag && ans>INT_MAX)return INT_MAX;
                        else if(!flag && ans>INT_MAX) return INT_MIN;
                    
                    i++;
            }else{
                i++;
                break;
            }
        }
        if(flag==false)return -1*ans;
        return ans;
    }
};