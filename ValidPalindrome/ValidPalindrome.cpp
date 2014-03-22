// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// For example,
// "A man, a plan, a canal: Panama" is a palindrome.
// "race a car" is not a palindrome.
// Note:
// Have you consider that the string might be empty? This is a good question to ask during an interview.
// For the purpose of this problem, we define empty string as valid palindrome. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isLetter(char c)
        {
            return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
        }

        bool isSameLetter(char c1, char c2)
        {
            if (c1 >= '0' && c1 <= '9')
            {
                return (c1 == c2);
            }
            if (c1 >= 'a' && c1 <= 'z')
            {
                return ((c1 == c2) || (c1 + ('A'-'a') == c2));
            }
            if (c1 >= 'A' && c1 <= 'Z')
            {
                return ((c1 == c2) || (c1 - ('A'-'a') == c2));
            }
        }

        bool isPalindrome(string s) {
            int l = s.length();
            int p = 0;
            int q = l-1;
            while (p < q)
            {
                if (!isLetter(s[p]))
                {
                    p++;
                    continue;
                }
                if (!isLetter(s[q]))
                {
                    q--;
                    continue;
                }
                if (!isSameLetter(s[p], s[q]))
                {
                    return false;
                }
                p++;
                q--;
            }
            return true;
        }
};

int main()
{
    string s = "A man, a plan, a canal: Panama.";

    Solution solu;
    cout << (solu.isPalindrome(s) ? "true" : "false") << endl;

    return 0;
}
