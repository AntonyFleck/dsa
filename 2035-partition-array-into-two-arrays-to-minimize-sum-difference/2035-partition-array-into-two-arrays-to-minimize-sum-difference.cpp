
class Solution {
public:
    void f(int index, int count, int tsum, int sum, int* diff,
           vector<int>& nums) {
        if (count == nums.size() / 2) {
            *diff = min(*diff, abs(sum-tsum+sum));
            return;
        }

        if (index >= nums.size())
            return;

        f(index + 1, count + 1, tsum, sum + nums[index], diff, nums);
        f(index + 1, count, tsum, sum, diff, nums);
    }

    int minimumDifference(vector<int>& nums) {

        int count = 0, tsum=0, sum=0;
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
            tsum += nums[i];

        // vector<vector<int>>(nums.size(),-1);

        f(0, count, tsum, sum, &diff, nums);
        return diff;
    }
};