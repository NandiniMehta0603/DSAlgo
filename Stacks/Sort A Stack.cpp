//steps: as we are not allowed to use any extra space
//pop out the top most element until the stack is empty
//while returning, insert the element at the bottom

void insertAtBottom(stack<int> &stack,int element){
    //base case
    if(stack.empty()){
        stack.push(element);
        return ;
    }

    int ele=stack.top();
    stack.pop();
    insertAtBottom(stack,element);
    stack.push(ele);
}

void solve(stack<int> &stack){
    //base case
    if(stack.empty()){
        return ;
    }

    int element=stack.top();
    stack.pop();
    solve(stack);
    insertAtBottom(stack,element);
}

void reverseStack(stack<int> &stack) {
    solve(stack);
}
