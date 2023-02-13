//as we require constant space for this question, so we will use 2 pointer approach
// starting index and ending index
//through recrsive calls,the start index and end index will traverse
#include <bits/stdc++.h> 
void solve(string &str,int start,int end){
	//base case
	if(start>end){
		return ;
	}
	solve(str,start+1,end-1);
	swap(str[start],str[end]);
}

string reverseString(string str)
{
	int start=0;
	int end=str.size()-1;

	solve(str,start,end);
	return str;
}
