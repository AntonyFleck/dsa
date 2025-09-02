class Solution {
public:
    bool isPossible(int cost, vector<int>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        // Array to mark the stones pos which are visited
        // so that they are not traversed in backward direction
        int ind = 0;
        while (ind < n - 1)
        // Checking in forward direction
        {
            int j = ind;
            // j se lekar i tak jitni pos cover ho rahi unko cover karlo
            // Goal is to minimize the number of stones jumped.
            while (j + 1 < n && stones[j + 1] <= stones[ind] + cost)
                j++;
            if (j == ind)
                // Agar j badha hi nahin vahin ka vahin rahe gaya
                return false;
            ind = j;
            // Updated position to the stone jumped
            visited[ind] = true;
            // Making the stone visited
        }

        // Optional we could have check while traversing
        // Storing positions of stones which are still to bs visited
        // Completely removing the visited Stone positions
        vector<int> indexes;
        for (int j = 0; j < n - 1; j++) {
            if (visited[j] == false)
                indexes.push_back(j);
        }
        indexes.push_back(n - 1);

        // Checking for backward direction
        ind = indexes.size() - 1;
        while (ind > 0) {
            int j = ind;
            // Covering as much stones as possible
            while (j > 0 && stones[indexes[j - 1]] >= stones[indexes[j]] - cost)
                j--;
            if (j == ind)
                return false;
            ind = j;
            // Updating the stone position
        }
        return true;
    }
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int low = 0;
        int high = stones[n - 1] - stones[0];
        // Range of cost
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(mid, stones))
            // Whether it is possible to traverse in both directions
            {
                high = mid - 1;
                // If possible then we will try to find more optimal lower cost
            } else
                low = mid + 1;
            // The cost required is higher then expected
        }
        return low;
    }
};