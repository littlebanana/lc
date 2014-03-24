// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given an encoded message containing digits, determine the total number of ways to decode it.
// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
// The number of ways decoding "12" is 2. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isCode(string s)
        {
            int l = s.length();
            if (l == 1)
            {
                return (s[0] >= '1' && s[0] <= '9');
            }
            else if (l == 2)
            {
                return ((s[0] == '1' && s[1] >= '0' && s[1] <= '9') || (s[0] == '2' && s[1] >= '0' && s[1] <= '6'));
            }
            return false;
        }

        void decode(const string &s, int left, int &ways)
        {
            int l = s.length();
            if (l == 0)
            {
                return;
            }
            if (left == l)
            {
                ways++;
                return;
            }
            if (left == l-1)
            {
                if (isCode(s.substr(left)))
                {
                    ways++;
                }
                return;
            }
            if (isCode(s.substr(left,1)))
            {
                decode(s, left+1, ways);
            }
            if (isCode(s.substr(left,2)))
            {
                decode(s, left+2, ways);
            }
        }

        // Recursion
        int numDecodings1(string s) {
            int ways = 0;
            decode(s, 0, ways);
            return ways;
        }

        // Dynamic programming
        int numDecodings2(string s) {
            if (s.empty())
            {
                return 0;
            }
            int l = s.length();
            int num[l+1];     // # of decoding ways for s[i...(l-1)]
            num[l] = 1;
            for (int i = l-1; i >= 0; i--)
            {
                num[i] = (isCode(s.substr(i,1)) ? num[i+1] : 0);
                if (i+2 <= l)
                {
                    num[i] += (isCode(s.substr(i,2)) ? num[i+2] : 0);
                }
            }
            return num[0];
        }
};

int main()
{
    string s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";

    Solution solu;
//    cout << solu.numDecodings1(s) << endl;    // so slow!
    cout << solu.numDecodings2(s) << endl;

    return 0;
}
