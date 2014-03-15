// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
    public:
        bool isValid(string s)
        {
            int L = s.length();
            stack<char> stk;
            for (int i = 0; i < L; i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    stk.push(s[i]);
                }
                else if (s[i] == ')')
                {
                    if (stk.empty() || stk.top() != '(')
                    {
                        return false;
                    }
                    stk.pop();
                }
                else if (s[i] == ']')
                {
                    if (stk.empty() || stk.top() != '[')
                    {
                        return false;
                    }
                    stk.pop();
                }
                else if (s[i] == '}')
                {
                    if (stk.empty() || stk.top() != '{')
                    {
                        return false;
                    }
                    stk.pop();
                }
            }
            return stk.empty();
        }

        // a more shorter version
        bool isValid2(string s) {
            stack<char> stk;
            int l = s.length();
            for (int i = 0; i < l; i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    stk.push(s[i]);
                }
                else if (stk.empty() || (s[i] != ')' && s[i] != ']' && s[i] != '}'))
                {
                    return false;
                }
                else if ((stk.top() == '(' && s[i] != ')') || (stk.top() == '[' && s[i] != ']') || (stk.top() == '{' && s[i] != '}'))
                {
                    return false;
                }
                else
                {
                    stk.pop();
                }
            }
            return stk.empty();
        }
};

int main()
{
    string s = "((()))";

    Solution solu;
    cout << "string = " << s << ", ";
    cout << (solu.isValid2(s) ? "yes" : "no") << endl;

    return 0;
}
