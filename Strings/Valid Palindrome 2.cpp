//step1: convert to lowercase
//check if valid character
//check for palindrome

class Solution {
public:
    char convert(char s){
    if(s>='a' && s<='z'){
        return s;
    }
    else{
        char temp=s-'A'+'a';
        return temp;
    }
}
bool alphanum(char s){
    if(s>='a' && s<= 'z' || s>='A' && s<='Z' || s>='0' && s<='9'){
        return true;
    }
    return false;
}
bool checkPalindrome(string s)
{
    int start=0;
    int end=s.size()-1;
    while(start<=end){
       if (alphanum(s[start]) == false)
           start++;
       else if (alphanum(s[end]) == false)
           end--;
       else if(convert(s[start]) != convert(s[end]))
           return false;
       else{
           start++;
           end--;
       }   
   }
   return true;
}

    bool isPalindrome(string s) {
        bool ans=checkPalindrome(s);
        return ans;
    }
};
