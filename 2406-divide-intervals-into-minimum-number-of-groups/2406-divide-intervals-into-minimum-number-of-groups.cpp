class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < intervals.size(); i++) {
            arr.push_back({intervals[i][0], 0});
            arr.push_back({intervals[i][1], 1});
        }
        sort(arr.begin(), arr.end());
        int count = 0;
        int answer = 1;
        for (int i = 0; i < arr.size(); i++) {

            if (arr[i].second == 0) {
                count++;
            } else {
                count--;
            }
            answer = max(answer, count);
        }
        return answer;
    }
};