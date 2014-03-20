// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
// Some examples:
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
    public:
        int parseInt(string s)
        {
            int i = 0;
            int l = s.length();

            // parse an optional sign
            bool sign = true;
            if (s[i] == '+' || s[i] == '-')
            {
                sign = (s[i] == '+');
                i++;
            }

            int num = 0;
            while (i < l)
            {
                num *= 10;
                num += (s[i++]-'0');
            }
            return (sign ? num : -num);
        }

        int evalRPN(vector<string> &tokens) {
            stack<int> stk;
            int n = tokens.size();
            for (int i = 0; i < n; i++)
            {
                if (tokens[i].compare("+") == 0)
                {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op1+op2);
                }
                else if (tokens[i].compare("-") == 0)
                {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2-op1);
                }
                else if (tokens[i].compare("*") == 0)
                {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op1*op2);
                }
                else if (tokens[i].compare("/") == 0)
                {
                    int op1 = stk.top();
                    stk.pop();
                    int op2 = stk.top();
                    stk.pop();
                    stk.push(op2/op1);
                }
                else
                {
                    int op = parseInt(tokens[i]);
                    stk.push(op);
                }
            }
            return stk.top();
        }
};

int main()
{
    vector<string> tokens(5);
    tokens[0] = "2";
    tokens[1] = "1";
    tokens[2] = "+";
    tokens[3] = "3";
    tokens[4] = "*";

    Solution solu;
    int result = solu.evalRPN(tokens);

    cout << result << endl;

    return 0;
}

