// Implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
// Some examples:
// isMatch("aa","a") ¡ú false
// isMatch("aa","aa") ¡ú true
// isMatch("aaa","aa") ¡ú false
// isMatch("aa", "a*") ¡ú true
// isMatch("aa", ".*") ¡ú true
// isMatch("ab", ".*") ¡ú true
// isMatch("aab", "c*a*b") ¡ú true

#include <iostream>

using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            if (*s == '\0' && *p == '\0')
            {
                return true;
            }
            if (*p == '\0')
            {
                return false;
            }
            if (*p == '*')      // skip multiple *
            {
                return isMatch(s, p+1);
            }

            if (*(p+1) != '*')
            {
                if (*s == '\0' || (*s != *p && *p != '.'))
                {
                    return false;
                }
                return isMatch(s+1, p+1);
            }
            else
            {
                if (isMatch(s, p+2))    // eliminate the first character in the pattern
                {
                    return true;
                }
                while (*s != '\0' && (*s == *p || *p == '.'))   // try to match one or more of the first character in the pattern
                {
                    if (isMatch(s+1, p+2))
                    {
                        return true;
                    }
                    s++;
                }
                return false;
            }
        }
};

int main()
{
    Solution solu;
    cout << (solu.isMatch("aa","a") ? "true" : "false") << endl;
    cout << (solu.isMatch("aa","aa") ? "true" : "false") << endl;
    cout << (solu.isMatch("aaa","aa") ? "true" : "false") << endl;
    cout << (solu.isMatch("aa","a*") ? "true" : "false") << endl;
    cout << (solu.isMatch("aa",".*") ? "true" : "false") << endl;
    cout << (solu.isMatch("ab",".*") ? "true" : "false") << endl;
    cout << (solu.isMatch("aab","c*a*b") ? "true" : "false") << endl;

    return 0;
}
