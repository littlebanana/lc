// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            char tab[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
            string roman;
            int i = 0;
            int pow10 = 10*10*10;
            while (num != 0)
            {
                int digit = num / pow10;

                if (digit < 4)
                {
                    roman.append(digit, tab[i]);
                }
                else if (digit == 4)
                {
                    roman += tab[i];
                    roman += tab[i-1];
                }
                else if (digit == 5)
                {
                    roman += tab[i-1];
                }
                else if (digit < 9)
                {
                    roman += tab[i-1];
                    roman.append(digit-5, tab[i]);
                }
                else
                {
                    roman += tab[i];
                    roman += tab[i-2];
                }

                i += 2;
                num %= pow10;
                pow10 /= 10;
            }
            return roman;
        }
};

int main()
{
    Solution solu;

    int x = 1024;
    cout << "x = " << x << ", roman = " << solu.intToRoman(x) << endl;

    return 0;
}
