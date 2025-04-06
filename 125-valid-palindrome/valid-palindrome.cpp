class Solution {
public:
    bool isPalindrome(string s) {
        string final1="";
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z' || (s[i]>='0' && s[i]<='9')){
                final1+=s[i];
            }else if(s[i]>='A' && s[i]<='Z'){
                final1+=s[i]-'A'+'a';
            }
        }
        cout<<final1;
        string a=final1;
        //now check if the reverse is equal or not
        reverse(final1.begin(),final1.end());
        return a==final1?true:false;
    }
};