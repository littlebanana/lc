// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
// Note: The sequence of integers will be represented as a string. 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if (n <= 0)
            {
                return "";
            }

            string code = "1";
            for (int i = 2; i <= n; i++)
            {
                // count and say the previous string
                string next("");
                int l = code.length();
                char num = code[0];
                int cnt = 1;
                for (int j = 1; j < l; j++)
                {
                    if (code[j] != num)
                    {
                        next += (cnt + '0');
                        next += num;
                        num = code[j];
                        cnt = 1;
                    }
                    else
                    {
                        cnt++;
                    }
                }
                next += (cnt+'0');
                next += num;

                code = next;
            }
            return code;
        }
};

int main()
{
    int n = 4;

    Solution solu;
    cout << solu.countAndSay(n) << endl;

    return 0;
}
