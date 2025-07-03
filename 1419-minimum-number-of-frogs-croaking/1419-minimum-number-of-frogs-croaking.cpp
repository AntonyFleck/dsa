class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int frogs = 0;
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            if (croakOfFrogs[i] == 'c')
                c++;
            else if (croakOfFrogs[i] == 'r')
                r++;
            else if (croakOfFrogs[i] == 'o')
                o++;
            else if (croakOfFrogs[i] == 'a')
                a++;
            else if (croakOfFrogs[i] == 'k')
                k++;
            else
                return -1;
            if (c < r || r < o || o < a || a < k)
                return -1;

            if (k > 0) {
                frogs = max(c, frogs);
                c--;
                r--;
                o--;
                a--;
                k--;
            }
        }
        if (a > 0 || c > 0 || r > 0 || o > 0 || k > 0)
            return -1;
        return frogs;
    }
};