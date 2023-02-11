//Steps: take tranpose of the matrix
//       swap the elements in the same row by col

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //step1: transpose
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<matrix[0].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //step2: swap the ele of each row column vise 
        //going row by row
        for(int i=0;i<matrix.size();i++){
            int start=0;
            int end=matrix[0].size()-1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};
