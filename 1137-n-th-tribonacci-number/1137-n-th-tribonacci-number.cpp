class Solution {
public:
    unordered_map<int, int> memo;
    int tribonacci(int n) {
        if (memo.find(n) != memo.end())
            return memo[n];
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;

        memo[n] = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
        return memo[n];
    }
};