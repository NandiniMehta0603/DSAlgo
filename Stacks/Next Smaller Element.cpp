
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    //step1: make a stack and push -1 to it
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
        int temp=arr[i];
        while(st.top()>=temp)
        {
            st.pop();
        }
        
        ans[i]=st.top();
        st.push(temp);
        
    }
    return ans;
}

