// Implement pow(x, n). 

#include <iostream>

using namespace std;

class Solution {
    public:
        // O(logN) Complexity
        double pow(double x, int n) {
            if (n == 0) {
                return 1.0;
            }
            if (n == 1) {
                return x;
            }
            if (n == -1) {
                // detour the n < 0 cases to this base case,
                // prevent overflow when straight negation
                return 1.0 / x;
            }

            int no2 = n/2;
            double po2 = pow(x, no2);
            if (n % 2 == 0) {
                // ok for both +, - int
                return po2*po2;
            } else {
                return (n > 0 ? x * po2 * po2 : po2 * po2 / x);
            }
        }

        double pow2(double x, int n) {
            if (n == 0) {
                return 1.0;
            }

            bool sign = n > 0;
            double hpow = pow(x, n / 2);
            if (n % 2 == 0) {
                return hpow * hpow;
            } else {
                return sign ? hpow * hpow * x : hpow * hpow / x;
            }
        }
};

int main() {
    Solution solu;
    double x = 3.2;
    int n = 3;
    cout << "pow(" << x << ", " << n << ") = " << solu.pow(x,n) << endl;

    return 0;
}
