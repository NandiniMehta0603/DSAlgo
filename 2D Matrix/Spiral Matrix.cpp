// steps: print in this order:
//          1.top row
//          2.rightmost column
//          3.bottom row
//          4.leftmost column
// keep on updating the values of i and j while printing the values in this order

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //toal no of rows
        int Rows=matrix.size();
        //total no of column
        int Cols=matrix[0].size();
        //total no of elements
        int total=Rows*Cols;

        int TopRow=0;//starting from top row
        int RightCol=Cols-1;//starting from the right most column
        int BottomRow=Rows-1;//starting from the bottom most row
        int LeftCol=0;//starting from the left most col

        vector<int> result;//to store thr result of the spiral print
        int count=0;
        while(count<total){
            //for printing top row, column value will change in every index
            for(int i=LeftCol;count<total && i<=RightCol;i++){
                result.push_back(matrix[TopRow][i]);
                count++;
            }
            TopRow++;

            //for printing right most col, row vale will change on evry iteration
            for(int j=TopRow;count<total && j<=BottomRow;j++){
                result.push_back(matrix[j][RightCol]);
                count++;
            }
            RightCol--;

            //for printing bottom most row, col value will change on every iteration
            for(int i=RightCol;count<total && i>=LeftCol;i--){
                result.push_back(matrix[BottomRow][i]);
                count++;
            }
            BottomRow--;

            //for traversing left most row,col value will change on every iteration
            for(int j=BottomRow;count<total && j>=TopRow;j--){
                result.push_back(matrix[j][LeftCol]);
                count++;
            }
            LeftCol++;
        }
        return result;
    }
};
