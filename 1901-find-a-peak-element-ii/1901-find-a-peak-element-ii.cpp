class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat[0].size();
        if (m == 1) {
            int maxi = INT_MIN;
            int index = -1;
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][0] > maxi) {
                    index = i;
                    maxi = mat[i][0];
                }
            }
            return {index, 0};
        }
        int low = 0, high = mat[0].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int maxi = INT_MIN;
            int index = -1;
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][mid] > maxi) {
                    index = i;
                    maxi = mat[i][mid];
                }
            }
            if (mid == 0) {
                if (mat[index][mid] > mat[index][mid + 1])
                    return {index, mid};
                else
                    low = mid + 1;
            } else if (mid == mat[0].size() - 1) {
                if (mat[index][mid] > mat[index][mid - 1])
                    return {index, mid};
                else
                    high = mid - 1;
            } else {
                if (mat[index][mid] > mat[index][mid - 1] &&
                    mat[index][mid] > mat[index][mid + 1])
                    return {index, mid};
                else if (mat[index][mid] < mat[index][mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return {};
    }
};