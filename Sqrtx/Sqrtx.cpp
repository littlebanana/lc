// Implement int sqrt(int x).
// Compute and return the square root of x.

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
        int sqrt(int x) {
            if (x < 0)
            {
                // maybe throw exception
                return -1;
            }
            if (x <= 1)
            {
                return x;
            }

            // Newton's method
            double xprev = -1.0;
            double xcurr = 1.0;
            while (abs(xprev-xcurr) >= 1.0)
            {
                xprev = xcurr;
                xcurr = (xprev + (double)x/xprev)/2.0;
            }
            return (int)xcurr;
        }

        int sqrt2(int x) {
            if (x < 0)
            {
                // maybe throw exception
                return -1;
            }
            if (x <= 1)
            {
                return x;
            }

            double low = 1;
            double high = 1;
            while (high*high < x)
            {
                high *= 2.0;
            }
            if (x == high*high)
            {
                return high;
            }

            while ((int)low != (int)high)
            {
                double mid = low + (high-low)/2.0;
                double mid_sq = mid*mid;
                if (mid_sq == x)
                {
                    return (int)mid;
                }
                else if (mid_sq < x)
                {
                    low = mid;
                }
                else
                {
                    high = mid;
                }
            }
            return (int)low;
        }
};

int main()
{
    Solution solu;
    cout << solu.sqrt(5) << endl;

    return 0;
}
