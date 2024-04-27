class Solution {
public:
   
    void removeSpecialCharacter(string &s)
{
    for (int i = 0; i < s.size(); i++) {
 
        // Finding the character whose
        // ASCII value fall under this
        // range
        if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a'
            || s[i] > 'z') && (s[i]<'0' || s[i]>'9')) {
            // erase fundction to erase
            // the character
            s.erase(i, 1);
            i--;
        }
    }
   
}
void toLowerCase(string &str){
    for(int i=0;i<str.size();i++){
        if(str[i]>='A' && str[i]<='z')
        str[i]=tolower(str[i]);
    }
    
}
    bool isPalindrome(string str) {
        //removing all abnormal entries like white space, and non-alphanumeric characters
        removeSpecialCharacter(str);
        cout<<str;
        toLowerCase(str);
        int i=0;
        int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
};