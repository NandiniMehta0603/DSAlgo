//condition: no extra length to be taken
//by using 3 pointers and single traversal of the vector 
//ansIndex pointer will point on the index position where any insert/change has to be done
//j point will traverse how many same characters are occuring together
//whenever the next char to j pointer is different than the current, j stops, count is given to ansIndex pointer and at the  ansIndex index, count value is inserted along the character
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int ansIndex=0;
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            chars[ansIndex]=chars[i];
            ansIndex++;
            int count=j-i;
            if(count>1){
                string ch=to_string(count);
                for(char m:ch){
                    chars[ansIndex++]=m;
                }
            }
            i=j;
        }
        return ansIndex;
    }
};
