class Solution {
public:
    string removeOuterParentheses(string str) {
        int n=str.size();
       int cnt=0;
        string s="";
        int removed=0;
        for(int i=0;i<n;i++){
                if(str[i]=='('){
                    if(cnt>0)s+=str[i];
                    cnt++;

                }else{
                    cnt--;
                    if(cnt>0)s+=str[i];
                }
        }

        return s;
    }
};