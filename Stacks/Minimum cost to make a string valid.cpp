#include <bits/stdc++.h> 
//optimisation- we have a formula for this question- so learn it
int findMinimumCost(string str) {
  if(str.length()%2!=0){
    return -1;
  }
  stack<char> st;
  for (int i = 0; i < str.length(); i++) {
    char ch = str[i];
    if (ch == '{'){
      st.push(ch);
    }
    else{
      if(!st.empty() && st.top()=='{'){
        st.pop();//as it forms a correct pair
      }
      else{
        st.push(ch);
      }
    }
  }
  int a = 0; // for keeping check on no of '{' brackets
  int b = 0; // for keeping check on no of '}' brackets
  while(!st.empty()){
    if(st.top()=='{')
    {
      a++;
      st.pop();
    }
    else{
      b++;
      st.pop();
    }
  }
  int ans=(a+1)/2+(b+1)/2;
  return ans;
}
