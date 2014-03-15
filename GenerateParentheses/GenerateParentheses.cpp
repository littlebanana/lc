// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
// "((()))", "(()())", "(())()", "()(())", "()()()" 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        void generate(const int n, int l, int u, string prev, vector<string> &combs)
        {
            // l = # of '(' in prev
            // u = # of unmatched '(' in prev

            if (l == n)
            {
                prev.append(u, ')');
                combs.push_back(prev);
            }
            else
            {
                // add one more '(' and go deeper
                generate(n, l+1, u+1, prev+'(', combs);

                // match one or more '(' in prev before add one more '( and go deeper
                for (int i = 1; i <= u; i++)
                {
                    prev += ')';
                    generate(n, l+1, u-i+1, prev+'(', combs);
                }
            }
        }

        vector<string> generateParenthesis(int n) {
            vector<string> combs;
            generate(n, 0, 0, "", combs);
            return combs;
        }

        void generate2(const int n, int open, int close, string prev, vector<string> &combs)
        {
            // open =  # of '(' left to be added
            // close = # of ')' left to be added

            if (open == 0 && close == 0)
            {
                combs.push_back(prev);
                return;
            }

            if (open > 0)
            {
                generate(n, open-1, close, prev+'(', combs);
            }
            if (close > open)
            {
                generate(n, open, close-1, prev+')', combs);
            }
        }

        // another approach
        vector<string> generateParenthesis2(int n) {
            vector<string> combs;
            generate2(n, n, n, "", combs);
            return combs;
        }
};

int main()
{
    Solution solu;
    vector<string> combs = solu.generateParenthesis2(3);

    for (int i = 0; i < combs.size(); i++)
    {
        cout << combs[i] << endl;
    }

    return 0;
}
