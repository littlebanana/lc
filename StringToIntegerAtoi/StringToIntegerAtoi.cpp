// Implement atoi to convert a string to an integer.
// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
// Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
// Requirements for atoi:
// The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
// Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
// If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
// If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

class Solution {
    public:
        int atoi(const char *str) {
            if (str == NULL || strlen(str) == 0)
            {
                return 0;
            }

            int l = strlen(str);

            // skip spaces in front
            int i = 0;
            for (; i < l && str[i] == ' '; i++);
            if (i == l)
            {
                return 0;
            }

            // parse an optional sign
            bool sign = true;
            if (str[i] == '+' || str[i] == '-')
            {
                sign = (str[i] == '+');
                i++;
            }

            if (i == l || str[i] > '9' || str[i] < '0')
            {
                return 0;
            }

            int x = (sign ? str[i]-'0' : -(str[i]-'0'));
            i++;
            while (i < l && str[i] >= '0' && str[i] <= '9')
            {
                int d = str[i] - '0';

                // test overflow
                if (sign && x > (double)(INT_MAX-d)/10.0)
                {
                    return INT_MAX;
                }
                if (!sign && x < (double)(INT_MIN+d)/10.0)
                {
                    return INT_MIN;
                }

                x *= 10;
                if (sign)
                {
                    x += d;
                }
                else
                {
                    x -= d;
                }
                i++;
            }
            return x;
        }
};

int main()
{
    Solution solu;

    char s[] = "0";
    cout << "s = " << s << ", int = " << solu.atoi(s) << endl;

    return 0;
}
