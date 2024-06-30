class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        stack<string>st;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp=="")continue;
                    st.push(temp);cout<<temp<<endl;
                    temp="";
            }else
            temp+=s[i];
        }
        while(st.size()!=1){
            string str=st.top();
            if(str==""){st.pop();continue;}
            temp+=str+' ';
            st.pop();
        }
        if(st.top()!=""){
            temp+=st.top();
        }
        return temp;
    }
};