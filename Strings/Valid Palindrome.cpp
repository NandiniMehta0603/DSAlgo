//check for uppercase and convert to lowercase
//ignore the extra characters
//check for palindrome

//function to convert uppercase to lower case
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
