//steps: *sliding window concept*
//make an array containing frequency of all letters of substring s1
//take window of size s1.length()
//check for the first window sze in s2 and compare the frequencies of letters in that window
//if frequencies are same return true
//if now, check for the next window
//for exploring the next window- add new character to the right and delete left most character
//update the frequency array accordingly

class Solution {
public:

    bool check(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        //step1: calculate freq of letters in s1
        int arr[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            arr[index]++;
        }
        //step2: take window size of length s1 and repeat step 1 for that window
        bool ans;
        int window_size=s1.length();

        int i=0;//for traversing the whole s2 string
        int arr1[26]={0};
        //only for first window
        while(i<window_size && i<s2.length()){
            int index=s2[i]-'a';
            arr1[index]++;
            i++;
        }
        //check for condition
        if(check(arr1,arr)){
            return true;
        }
        //check for aage ki window abh
        //repeat same steps
        while(i<s2.length()){
            //1 element add kardp
            char newChar=s2[i];
            int index=newChar-'a';
            arr1[index]++;

            //left element hatado
            char oldChar=s2[i-window_size];
            int oldIndex=oldChar-'a';
            arr1[oldIndex]--;

            i++;
            //check for the condition
            if(check(arr1,arr)){
                return true;
            }
        }
        return false;      
    }
};
