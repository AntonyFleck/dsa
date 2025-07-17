class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int r = 0,i=0, l = 0, count = 0,sum=0,temp=0;
        while (i < nums.size()) {
            nums[i]=nums[i]%2;
            i++;
        }
        while (r < nums.size()) {
            if (nums[r] == 0)
                sum++;
            // if (goal == 0) {
            //     if (r - l + 1 - sum > goal) {
            //         while (l < r) {
            //             if (nums[l] == 0)
            //                 sum--;
            //             l++;
            //         }
            //     }

            // } else {
        if (r - l + 1 - sum > goal) {
                    while (nums[l] != 1 && l < r) {
                        sum--;
                        l++;
                    }
                    l++;
                    if(l>r){
                        r=l;
                        continue;
                    }
                }
            if (r - l + 1 - sum == goal) {
                count++;
                if (nums[l] == 0) {
                    temp = l;
                    while (nums[temp] != 1 && temp < r) {
                        count++;
                        temp++;
                    }
                }
            }

            r++;
        }


        return count;
    }
};