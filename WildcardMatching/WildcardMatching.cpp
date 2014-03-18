#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            int Ls = strlen(s);
            int Lp = strlen(p);
            int i = 0;
            int j = 0;
            int is = -1;
            int js = -1;
            while (i < Ls)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    i++;
                    j++;
                }
                else if (p[j] == '*')
                {
                    for (; j < Lp && p[j] == '*'; j++);
                    if (j == Lp)
                    {
                        return true;
                    }
                    is = i;
                    js = j;     // character after '*' for next match
                }
                else if (p[j] != '*' && js != -1)
                {
                    i = (++is);
                    j = js;
                }
                else
                {
                    return false;
                }
            }

            while (j < Lp)
            {
                if (p[j] != '*')
                {
                    return false;
                }
                j++;
            }
            return true;
        }

        bool isMatch2(const char *s, const char *p) {

            if (*s == '\0' && *p == '\0')
            {
                return true;
            }
            if (*p == '\0')
            {
                return false;
            }
            if (*p != '*')
            {
                if (*s == '\0' || (*s != *p && *p != '?'))
                {
                    return false;
                }
                return isMatch(s+1, p+1);
            }
            else
            {
                // skip multiple *
                for (; *p == '*'; p++);

                do  // execute at least once for the case s = ""  and p = ""
                {
                    if (isMatch(s, p))
                    {
                        return true;
                    }
                    s++;
                } while (*s != '\0');
                return false;
            }
        }

        bool isMatch3(const char *s, const char *p) {
            const char *si = NULL;
            const char *pi = NULL;
            while (*s != '\0')
            {
                if (*p == '\0' || *p != '*')
                {
                    if (*s != *p && *p != '?')
                    {
                        if (si != NULL)
                        {
                            s = ++si;
                            p = pi;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        s++;
                        p++;
                    }
                }
                else
                {
                    // skip multiple *'s
                    for (; *p == '*'; p++);
                    if (*p == '\0')
                    {
                        return true;
                    }

                    si = s;
                    pi = p;
                }
            }
            while (*p != '\0')
            {
                if (*p != '*')
                {
                    return false;
                }
                p++;
            }
            return true;
        }
};

int main()
{
    char S[] = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
    char P[] = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";

    Solution solu;
    cout << solu.isMatch2(S, P) << endl;

    return 0;
}
