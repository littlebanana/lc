// Given an input string, reverse the string word by word.
// For example,
// Given s = "the sky is blue", return "blue is sky the".
// Clarification:
// - What constitutes a word?
//   A sequence of non-space characters constitutes a word.
// - Could the input string contain leading or trailing spaces?
//   Yes. However, your reversed string should not contain leading or trailing spaces.
// - How about multiple spaces between two words?
//   Reduce them to a single space in the reversed string.


#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        void reverseWords(string &s) {
            int l = s.length();

            // skip the trailing spaces
            int i = l-1;
            for (; i >= 0 && s[i] == ' '; i--);
            if (i < 0)
            {
                s = "";
                return;
            }

            string buffer;
            while (i >= 0)
            {
                // parse one word
                int j = i;
                for (; j >= 0 && s[j] != ' '; j--);

                buffer += s.substr(j+1, i-j);
                if (j < 0)
                {
                    s = buffer;
                    return;
                }

                // skip spaces
                for (; j >= 0 && s[j] == ' '; j--);
                if (j < 0)
                {
                    s = buffer;
                    return;
                }

                // append a seperator
                buffer += " ";
                i = j;
            }
            s = buffer;
        }
};

int main()
{
    string s = "    the sky    is blue   ";

    Solution solu;

    cout << "s = " << s << ", reversed = ";

    solu.reverseWords(s);

    cout << s << "." << endl;

    return 0;
}
