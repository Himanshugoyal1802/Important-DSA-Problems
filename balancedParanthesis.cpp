/*

            //approach
            TC - n
            SC - n

use stack to store brackets

Code:

bool isValid(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(!st.empty() && ( (s[i] == ')' && st.top()=='(') || (s[i] == '}' && st.top() == '{') || 
               (s[i] == ']' && st.top() == '['))){
                st.pop();
            }
            else{st.push(s[i]);}
        }
        
        if(st.size()>0)return false;
        return true;
    }

*/