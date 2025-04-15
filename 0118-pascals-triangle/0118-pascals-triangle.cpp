class Solution {
public:
    vector<vector<int>> array;
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1)
            return {{1}};
        if (numRows == 2)
            return {{1}, {1, 1}};

        array = generate(numRows - 1);
        vector<int> temp;
        temp.push_back(1);
        for (int i = 0; i < array[numRows - 2].size()-1; i++) {
            temp.push_back(array[numRows - 2][i] + array[numRows - 2][i + 1]);
        }
        temp.push_back(1);
        array.push_back(temp);
        return array;
    }
};