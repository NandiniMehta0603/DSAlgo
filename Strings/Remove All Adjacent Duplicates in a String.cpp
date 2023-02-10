//make a temp string in whuch you have to compare the last pushed element of temp to the incoming char of s string
//if the last ele of temp is same as first ele of s, --> occurence of 2 same characters, so pop back the last pushed char of temp
//if not same means only single occurence of the char at the moment
//this is kinda an appliaction of queues

class Solution {
public:
    string removeDuplicates(string s) {
        string temp="";
        temp+=s[0];
        int i=1;
        while(i<s.length()){
            if(s[i]!=temp.back()){
                temp.push_back(s[i]);
            }
            else{
                temp.pop_back();
            }
            i++;
        }
        return temp;
    }
};
