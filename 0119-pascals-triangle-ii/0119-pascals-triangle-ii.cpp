class Solution {
public:
    vector<int> getRow(int rowIndex) {
       vector<vector<int>> array = {{1}, {1, 1}};
        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return {1, 1};
        for (int i = 2; i <= rowIndex; i++) {
            array.push_back({});
            array[i].push_back(1);
            for (int j = 0; j <= i-2; j++) {
                array[i].push_back(array[i-1][j]+array[i-1][j+1]);
            }
            array[i].push_back(1);
        }
        return array[rowIndex];
    }
};