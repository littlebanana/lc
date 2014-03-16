// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> stk;
            int len = 0;
            int prev = -1;          // prev+1 = the start of this matched parentheses
            int l = s.length();
            for (int i = 0; i < l; i++)
            {
                if (s[i] == ')')
                {
                    if (stk.empty())
                    {
                        prev = i;
                    }
                    else // if (s[stk.top()] == '(')
                    {
                        stk.pop();
                        len = max(len, (stk.empty() ? i-prev : i-stk.top()));
                    }
                }
                else
                {
                    stk.push(i);
                }
            }
            return len;
        }
};

int main()
{
    string s = "(()()(";

    Solution solu;
    cout << s << ", length of longest valid parentheses is " << solu.longestValidParentheses(s) << endl;

    return 0;
}
