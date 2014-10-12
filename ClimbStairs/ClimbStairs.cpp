// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        
        // Dynamic programming
        // Fibonacci's squence
        int pp = 1;     // # of ways for i-2 steps
        int p = 1;      // # of ways for i-1 steps
        for (int i = 2; i <= n; i++) {
            int ways = pp + p;
            pp = p;
            p = ways;
        }
        return p;
    }
};

int main() {
    Solution solu;
    int n = 3;
    cout << "n = " << n << ", # of ways = " << solu.climbStairs(n) << endl;

    return 0;
}
