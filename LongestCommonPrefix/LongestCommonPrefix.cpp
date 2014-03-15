// Write a function to find the longest common prefix string amongst an array of strings.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        string commonPrefix(string s1, string s2)
        {
            if (s1.empty() || s2.empty())
            {
                return "";
            }

            int l1 = s1.length();
            int l2 = s2.length();
            int i = 0;
            for (; i < l1 && i < l2 && s1[i] == s2[i]; i++);

            if (i == l1)
            {
                return s1;
            }
            else if (i == l2)
            {
                return s2;
            }
            else
            {
                return s1.substr(0, i);
            }
        }

        string findPrefix(const vector<string> &strs, int left, int right)
        {
            if (left > right)
            {
                return "";
            }
            if (left == right)
            {
                return strs[left];
            }
            if (left + 1 == right)
            {
                return commonPrefix(strs[left], strs[right]);
            }
            int mid = left + (right-left)/2;
            string s1 = findPrefix(strs, left, mid);
            string s2 = findPrefix(strs, mid+1, right);
            return commonPrefix(s1, s2);
        }

        string longestCommonPrefix1(vector<string> &strs) {
            return findPrefix(strs, 0, strs.size()-1);
        }

        string longestCommonPrefix2(vector<string> &strs) {
            if (strs.empty())
            {
                return "";
            }
            int n = strs.size();
            string common = strs[0];
            for (int i = 1; i < n; i++)
            {
                common = commonPrefix(common, strs[i]);
            }
            return common;
        }

        string longestCommonPrefix(vector<string> &strs) {
            if (strs.empty())
            {
                return "";
            }

            vector<string> tmp = strs;
            int n = tmp.size();
            for (int l = 1; l < n; l *= 2)          // offset of mid
            {
                for (int i = 0; i < n; i += 2*l)    // start
                {
                    int j = i + l;
                    if (j < n)
                    {
                        tmp[i] = commonPrefix(tmp[i], tmp[j]);
                    }
                }
            }
            return tmp[0];
        }
};

int main()
{
    vector<string> str;
    str.push_back("a");
    str.push_back("a");
    str.push_back("b");

    Solution solu;
    cout << solu.longestCommonPrefix(str) << endl;


    return 0;
}
