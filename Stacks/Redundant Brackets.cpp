#include <bits/stdc++.h> 
//steps: just like redundant brackets, there should equal no of brackets as the no of operations

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(' || ch=='*' || ch=='+' || ch=='-' || ch=='/'){
            st.push(ch);
        }
        else{
            bool isRedundant=true;
            if(ch==')')
            {
                while(st.top()!='('){
                    if(st.top()=='*' || st.top()=='/' || st.top()=='+' || st.top()=='-'){
                        isRedundant=false;
                        st.pop();
                    }
                    else{
                        isRedundant=true;
                    }
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
            
        }
    }
    return false;
}
