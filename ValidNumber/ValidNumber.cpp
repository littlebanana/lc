// Validate if a given string is numeric.
// Some examples:
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
// Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        bool isNumber(const char *s) {
            int l = strlen(s);
            int i = 0;
            bool dot = false;
            bool exp = false;

            // skip the leading spaces
            for (; i < l && s[i] == ' '; i++);
            if (i == l)
            {
                return false;
            }

            // parse an optional sign
            if (s[i] == '+' || s[i] == '-')
            {
                i++;
            }
            if (i == l)
            {
                return false;
            }

            // parse an optional dot
            if (s[i] == '.')
            {
                dot = true;
                i++;
            }

            // parse a numeric letter
            if (i == l || s[i] < '0' || s[i] > '9')
            {
                return false;
            }
            i++;

            while (i < l)
            {
                if (s[i] == ' ')
                {
                    break;
                }
                else if (s[i] == '.')    // must be followed by a numeric letter
                {
                    if (dot || exp)
                    {
                        return false;
                    }
                    dot = true;

                    // parse one numeric letter
                    i++;
                    /*if (i == l || s[i] < '0' || s[i] > '9')
                      {
                      return false;
                      }
                      i++;*/
                }
                else if (s[i] == 'e' || s[i] == 'E')    // must be followed by an optional sign + a numeric letter
                {
                    if (exp)
                    {
                        return false;
                    }
                    exp = true;

                    i++;
                    if (s[i] == '+' || s[i] == '-')
                    {
                        i++;
                    }
                    if (i == l || s[i] < '0' || s[i] > '9')
                    {
                        return false;
                    }
                    i++;
                }
                else if (s[i] < '0' || s[i] > '9')
                {
                    return false;
                }
                else
                {
                    i++;
                }
            }

            while (i < l)
            {
                if (s[i] != ' ')
                {
                    return false;
                }
                i++;
            }
            return true;
        }
};

int main()
{
    char s[] = "1e.";

    Solution solu;
    cout << (solu.isNumber(s) ? "true" : "false") << endl;

    return 0;
}
