// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isByte(string s)
        {
            int l = s.length();
            if (l == 1)
            {
                return (s[0] >= '0' && s[0] <= '9');
            }
            else if (l == 2)
            {
                return (s[0] >= '1' && s[0] <= '9' && s[1] >= '0' && s[1] <= '9');
            }
            else if (l == 3)
            {
                return ((s[0] == '1' && s[1] >= '0' && s[1] <= '9' && s[2] >= '0' && s[2] <= '9')
                        || (s[0] == '2' && s[1] >= '0' && s[1] <= '4' && s[2] >= '0' && s[2] <= '9')
                        || (s[0] == '2' && s[1] == '5' && s[2] >= '0' && s[2] <= '5'));
            }
            return false;
        }

        void restore(const string s, int left, string prev, int cnt, vector<string> &ips)
        {
            int l = s.length();
            if (left >= l)
            {
                return;
            }

            if (cnt == 3)
            {
                if (isByte(s.substr(left)))
                {
                    prev += s.substr(left);
                    ips.push_back(prev);
                }
                return;
            }

            for (int i = 1; i <= 3; i++)
            {
                if (isByte(s.substr(left,i)))
                {
                    restore(s, left+i, prev+s.substr(left,i)+".", cnt+1, ips);
                }
            }
        }

        vector<string> restoreIpAddresses(string s) {
            vector<string> ips;
            restore(s, 0, "", 0, ips);
            return ips;
        }
};

int main()
{
    string s = "123255212";

    Solution solu;
    vector<string> ips = solu.restoreIpAddresses(s);

    for (int i = 0; i < ips.size(); i++)
    {
        cout << ips[i] << endl;
    }

    return 0;
}
