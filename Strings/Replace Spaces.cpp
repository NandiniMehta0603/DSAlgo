#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	string ans="";
	for(int i=0;i<str.size();i++){
		if(str[i]!=' '){
			ans.push_back(str[i]);
		}
		else{
			ans.push_back('@');
			ans.push_back('4');
			ans.push_back('0');
		}
	}
	return ans;
}
