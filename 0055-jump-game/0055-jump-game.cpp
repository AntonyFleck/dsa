class Solution {
public:
    int i = 0;
    bool result = false;
    unordered_map<int, bool> hash;

    bool canJump(vector<int>& nums) {
        if (i == nums.size() - 1){
            return true;
        }
        if (i > nums.size() - 1)
            return false;
        int temp = nums[i];

        if (hash.find(i) != hash.end())
            return hash[i];

        // cout << i << " " << temp << endl;
        for (int k = 0; k < temp; k++) {
            int y = i;
            i += nums[i];
            // cout << i << "mo" << endl;
            result = canJump(nums);
            if(result)
                return true;
            i = y;
            // cout << i << "yess" << endl;
            nums[i]--;
        }
        if (!result) {
            hash[i] = false;
        }

        return result;
    };
};
