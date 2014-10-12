// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321
// Have you thought about this?
// Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
// Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
// Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        int reverse(int x) {
            bool sign = (x > 0);
            int y = 0;
            while (x != 0) {
                int d = x % 10;     // + % 10 = +, - % 10 = -

                // test overflow
                if (sign && y > (double)(INT_MAX-d)/10.0) {
                    return INT_MAX;
                }
                if (!sign && y < (double)(INT_MIN-d)/10.0) {
                    return INT_MIN;
                }

                y *= 10;
                y += d;

                x /= 10;
            }
            return y;
        }
};

int main() {
    Solution solu;

    int x = 0;
    cout << "x = " << x << ", reverse = " << solu.reverse(x) << endl;
    x = 10;
    cout << "x = " << x << ", reverse = " << solu.reverse(x) << endl;
    x = 123;
    cout << "x = " << x << ", reverse = " << solu.reverse(x) << endl;
    x = -10;
    cout << "x = " << x << ", reverse = " << solu.reverse(x) << endl;
    x = -123;
    cout << "x = " << x << ", reverse = " << solu.reverse(x) << endl;

    return 0;
}
