// Given a roman numeral, convert it to an integer.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            int num = 0;
            int l = s.length();
            for (int i = l-1; i >= 0; i--)
            {
                if (s[i] == 'I')
                {
                    num += 1;
                }
                else if (s[i] == 'V')
                {
                    if (i > 0 && s[i-1] == 'I')
                    {
                        num += 4;
                        i--;
                    }
                    else
                    {
                        num += 5;
                    }
                }
                else if (s[i] == 'X')
                {
                    if (i > 0 && s[i-1] == 'I')
                    {
                        num += 9;
                        i--;
                    }
                    else
                    {
                        num += 10;
                    }
                }
                else if (s[i] == 'L')
                {
                    if (i > 0 && s[i-1] == 'X')
                    {
                        num += 40;
                        i--;
                    }
                    else
                    {
                        num += 50;
                    }
                }
                else if (s[i] == 'C')
                {
                    if (i > 0 && s[i-1] == 'X')
                    {
                        num += 90;
                        i--;
                    }
                    else
                    {
                        num += 100;
                    }
                }
                else if (s[i] == 'D')
                {
                    if (i > 0 && s[i-1] == 'C')
                    {
                        num += 400;
                        i--;
                    }
                    else
                    {
                        num += 500;
                    }
                }
                else
                {
                    if (i > 0 && s[i-1] == 'C')
                    {
                        num += 900;
                        i--;
                    }
                    else
                    {
                        num += 1000;
                    }
                }
            }
            return num;
        }
};

int main()
{
    Solution solu;

    string s = "XIIV";
    cout << "s = " << s << ", num = " << solu.romanToInt(s) << endl;

    return 0;
}
