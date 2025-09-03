/*
State:
    i: floor Alice is on
    jump: factor of jump operation
    down: did Alice go down in the previous step

Operations:
    down: --i, down = true
    up: i += pow(2, jump), ++jump

Goal is k, we can model an equation below:
k = 1 + (2^0 + 2^1 + 2^2 + ... 2^(x - 1)) - y
  = 1 + (2^x - 1) / (2 - 1) - y
  = 1 + (2^x - 1) - y
  = 2^x - y

step 1) 2^x >= k, find the least value of x satisfy the above equation
        x >= ln(k)/ln(2)
        x = (int)(ceil(log(k)/log(2)))        
step 2) y = 2^x - k
step 3) find the number of ways to slot y inside x -> (x + 1)C (y)
step 4) increment x value found in 1) and repeat step 2 - 3 until a value of y > x

where x is number of up operations and y is the number of down operations

*/
class Solution {
public:
    static int nCr(int n, int r) {
        if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
        long long ans = 1;
        for(int i = 1; i <= r; i++) {
            ans *= n - r + i;
            ans /= i;
        }
        return ans;
    }

    int waysToReachStair(int k) {
        if(k==0 || k==4) return 2;
        if(k==1 || k==2) return 4;
        int x = ceil(log2(k));
        int ways = 0;
        while (true) {
            int y = pow(2, x) - k;
            if (y >= (x + 2)) break;
            ways += nCr(x + 1, y);
            ++x;
        }
        return ways;
    }
};