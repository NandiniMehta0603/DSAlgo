#include <bits/stdc++.h> 
//steps: as size of stack is given
//start from Nth index
// you have to delete N+1/2th index
//so by then give recursive calls and the moment base case is reached, pop

void solve(stack<int>&inputStack,int N,int i){
   //base case
   if(i==(N+1)/2){
      inputStack.pop();
      return ;
   }

   int element=inputStack.top();
   inputStack.pop();
   solve(inputStack,N,i-1);
   //upon returning push back the element
   inputStack.push(element);

}

void deleteMiddle(stack<int>&inputStack, int N){
	int i=N;
   solve(inputStack,N,i);
}
