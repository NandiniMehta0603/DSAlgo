class Solution {
public:
    int solve(string &text1,string &text2){
        int n1=text1.length();
        int n2=text2.length();

        vector<int> curr(n2+1,0);
        vector<int> next(n2+1,0);

        for(int i=n1-1;i>=0;i--){
            for(int j=n2-1;j>=0;j--){
                int ans=0;
                if(text1[i]==text2[j]){
                    ans=1+next[j+1];
                }
                else{
                    ans=max(next[j],curr[j+1]);
                }
                curr[j]=ans;
            }
            next=curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string text1=s;
        reverse(text1.begin(),text1.end());

        return solve(s,text1);
    }
};
