class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int longestOdd=-1;
        string ans="";
        string temp="";
        for(int i=0;i<n;i++){
            temp+=num[i];
            if((num[i]-'0')%2==1){
                longestOdd=i;
                ans=temp;
            }
        }
        
        return ans;

    }
};