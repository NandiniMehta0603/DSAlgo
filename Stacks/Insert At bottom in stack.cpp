#include <bits/stdc++.h> 
//steps: pop out all the elements of the stack using recusrion
//then push the new element
//while returning push back all the taken out elements

void solve(stack<int> &myStack,int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int element=myStack.top();
    myStack.pop();
    solve(myStack,x);
    myStack.push(element);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack,x);
    return myStack;
}
