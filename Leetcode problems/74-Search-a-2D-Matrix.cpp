class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols =  matrix[0].size();

        int top_row = 0;
        int bot_row = rows-1;

        // first binary search to find with row the number might be
        while(top_row <= bot_row){
            int mid_row = (bot_row + top_row)/2;
            if(matrix[mid_row][cols-1] < target){
                top_row = mid_row + 1;
            }
            else if(matrix[mid_row][0] > target){
                bot_row = mid_row - 1;
            }
            else{
                break;
            }
        }

        if (top_row > bot_row){
            return false;
        }
        // now we have the row -> mid_row
        // matrix[mid_row][else]

        int mid_row = (bot_row + top_row)/2;

        int l = 0;
        int r= cols-1;
        
        while(l <= r){
            int mid = (l+r) /2;
            if(matrix[mid_row][mid] > target){ // first half , change right
                r = mid-1;
            }
            else if(matrix[mid_row][mid] < target){
                l = mid + 1;
            }
            else{ // we found the number
                return true;
            }
        }
        return false;
    }
};