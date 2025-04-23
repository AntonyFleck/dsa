// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int req = 0;
//         if (height.size() == 1)
//             return 0;
//         int left = 0;
//         while (left < height.size()) {
//             if (height[left] != 0)
//                 break;
//             left++;
//         }
//         int end = height.size() - 1;
//         while (left < height.size() - 1) {
//             if (height[left] != height[left + 1])
//                 break;
//             left++;
//         }
//         while (end >= height.size() - 1) {
//             if (height[end] != height[end - 1])
//                 break;
//             end--;
//         }

//         int right = left;
//         int temp;
//         int buckets = 0;
//         if (height[end] < height[end - 1])
//             end--;
//         while (left <= right && right < end) {
//             if (req == 0) {
//                 int test = right + 1;
//                 int flag = 0;
//                 int maxi = 0;
//                 while (test <= end) {
//                     if (height[right] > height[test]) {
//                         maxi = max(maxi, height[test]);
//                         test++;

//                     } else {
//                         flag = 1;
//                         break;
//                     }
//                 }
//                 if (flag == 0) {
//                     height[right] = maxi;

//                 }
//             }
//             req = 1;
//             temp=height[left];
//             if (height[++right] < height[left]) {
//                 temp = height[left];
//             } else {
//                 while (left < right && right <= end) {
//                     buckets += (temp - height[left]);
//                     left++;
//                 }
//                 req = 0;
//             }
//         }
//         return buckets;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left++];
        } else {
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right--];
        }
    }
    return water;
    }
};