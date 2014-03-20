// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.
// For example,
// Given s = "Hello World",
// return 5.

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            int i = 0;
            int n = strlen(s);

            // parse the additional spaces in the front
            for (; i < n && s[i] == ' '; i++);
            if (i == n)
            {
                return 0;
            }

            int l = 0;
            while (i < n)
            {
                // parse one word
                int j = i;
                for (; j < n && s[j] != ' '; j++);
                l = j - i;

                // skip the following spaces
                for (; j < n && s[j] == ' '; j++);

                if (j == n)
                {
                    return l;
                }

                i = j;
            }
            return l;
        }
};

int main()
{
    char s[] = "Hello World";

    Solution solu;
    cout << solu.lengthOfLastWord(s) << endl;

    return 0;
}
