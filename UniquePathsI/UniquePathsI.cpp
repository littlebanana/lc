// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
// How many possible unique paths are there?
// Note: m and n will be at most 100.

#include <iostream>

using namespace std;

class Solution {
public:
    int C1(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }
        
        int nmk = n - k;
        k = (nmk > k ? k : nmk);
        if (k == 1) {
            return n;
        }
        
        long long int did = n;
        for (int i = 1; i < k; i++) {
            did *= (n-i);
        }
        long long int div = 1;
        for (int i = 2; i <= k; i++) {
            div *= i;
        }
        return (int)(did / div);
    }

    int gcd(int a, int b) {
        // Euclidean algorithm
        while (b != 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
    }

    int C2(int n, int k) {
        if (k == 0 || k == n) {
            return 1;
        }
        
        k = ((n-k) > k ? k : (n-k));
        if (k == 1) {
            return n;
        }

        int result = 1;
        for (int i = 1; i <= k; i++) {
            int did = (n-i+1);
            int div = i;
            int c = gcd(did, div);      // tricky, not fully understand
            did /= c;                   // order is also tricky
            div /= c;
            result /= div;
            result *= did;
        }
        return result;
    }

    inline int C(int n, int k) {
        return C2(n, k);
    }

    // Apporach 1: combinatoric, (m+n-2) steps, choos (m-1) steps to go down
    int uniquePaths1(int m, int n) {
        return C(m+n-2, m-1);
    }

    // Approach 2: Dynamic programming
    int uniquePaths2(int m, int n) {
        if (m < n) {
            swap(m, n);
        }
        
        // num[i][j] = num[i-1][j] + num[i][j-1]
        int num[n];     // num[i]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    num[j] = 1;
                } else {
                    num[j] += num[j-1];
                }
            }
        }
        return num[n-1];
    }
};

int main() {
    Solution solu;
    cout << solu.uniquePaths2(10, 10) << endl;

    return 0;
}
