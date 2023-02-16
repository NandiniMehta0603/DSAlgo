//steps: letter combinations mean that we need to create subsets-all possible subsets
//first of all create a mapping sysem that maps numbers to their respective letters
//then with those string of letters create all possible subsets

class Solution {
public:
    void solve(string digits,string output, vector<string> &ans, string mapping[],int index){
        //base case
        if(index>=digits.length()){
            ans.push_back(output);
            return ;
        }

        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,ans,mapping,index+1);
            //as we cant store the full answer and have to trace back..exclude this value
            output.pop_back();//basically there is no exclude call, so we have to move ahead like this
        }
    }

    vector<string> letterCombinations(string digits) {
        //create an empty string
        string output="";

        //create the ans vector to store all the output strings
        vector<string> ans;

        //add base case here also
        if(digits.length()==0){
            return ans;
        }

        //create a mapping system
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        //call for the function to calculate the substrings
        solve(digits,output,ans,mapping,0);

        return ans;

    }
};
