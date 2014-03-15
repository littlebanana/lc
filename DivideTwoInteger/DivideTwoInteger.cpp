// Divide two integers without using multiplication, division and mod operator. 

#include <iostream>

using namespace std;

class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Be careful with the sign, overflow when negate, and divided by 0, etc.

            if (divisor == 0)
            {
                // maybe throw an exception
                return 0;
            }
            if (dividend == 0)
            {
                return 0;
            }

            bool sign = (dividend > 0 && divisor > 0 || dividend < 0 && divisor < 0);

            // avoid overflow when negation
            long long did = (long long)dividend;
            long long div = (long long)divisor;
            did = (did < 0 ? -did : did);
            div = (div < 0 ? -div : div);

            long long quot = 0;
            while (did > 0)
            {
                int shift = 0;
                long long mult = div;
                while (mult <= did)
                {
                    shift++;
                    mult <<= 1;     // watch out the syntax
                }

                quot += (shift == 0 ? 0 : 1<<(shift-1));
                did -= (shift == 0 ? mult : mult>>1);
            }

            return (int)(sign ? quot : -quot);
        }
};

int main()
{
    int did = 10;
    int div = 3;
    
    Solution solu;
    cout << did << " / " << div << " = " << solu.divide(did, div) << endl;

    return 0;
}
