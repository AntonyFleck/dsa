class Solution {
public:
    void game(int n, int& turn) {
        if (n <= 0)
            return;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                turn++;
                cout << n << "&" << i << endl;
                game(n - i, turn);
            }
        }
        return;
    }
    bool divisorGame(int n) {
        // int turn = 1;
        // game(n, turn);
        // cout << turn << endl;
        if (n % 2 == 0)
            return true;
        return false;
    }
};