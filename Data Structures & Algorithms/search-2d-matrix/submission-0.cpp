class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int l =0;
        int r = rows * cols -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            int ro = m / cols;
            int co = m % cols;
            if(target > matrix[ro][co]){
                l = m + 1;
            }
            else if(target < matrix[ro][co]){
                r = m - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
