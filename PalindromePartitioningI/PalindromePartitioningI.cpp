// Given a string s, partition s such that every substring of the partition is a palindrome.
// Return all possible palindrome partitioning of s.
// For example, given s = "aab",
// Return
//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        // recursion
        void generate(const string &s, int left, const vector<vector<bool> > &tab, vector<string> parts, vector<vector<string> > &set)
        {
            int l = s.length();
            if (left == l)
            {
                set.push_back(parts);
                return;
            }

            for (int i = left; i < l; i++)
            {
                if (tab[left][i])
                {
                    vector<string> tmp = parts;
                    tmp.push_back(s.substr(left,i-left+1));
                    generate(s, i+1, tab, tmp, set);
                }
            }
        }

        vector<vector<string> > partition(string s) {
            int l = s.length();

            // build up palindrome table
            // tab[i][j] = whether s[i...j] is a palindrome
            // tab[i][j] = tab[i+1][j-1] && s[i] == s[j]
            vector<vector<bool> > tab(l, vector<bool>(l));
            for (int i = l-1; i >= 0; i--)
            {
                for (int j = i; j < l; j++)
                {
                    if (i == j)
                    {
                        tab[i][j] = true;
                    }
                    else if (i+1 == j)
                    {
                        tab[i][j] = (s[i] == s[j]);
                    }
                    else
                    {
                        tab[i][j] = (tab[i+1][j-1] && (s[i] == s[j]));
                    }
                }
            }

            vector<vector<string> > set;
            vector<string> parts;
            generate(s, 0, tab, parts, set);
            return set;
        }
};

int main()
{
    string s = "aab";
    Solution solu;
    vector<vector<string> > parts = solu.partition(s);

    for (int i = 0; i < parts.size(); i++)
    {
        for (int j = 0; j < parts[i].size(); j++)
        {
            cout << parts[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
