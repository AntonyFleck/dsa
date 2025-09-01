class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix[0].size() * matrix.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / matrix[0].size(), col = mid % matrix.size();
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};