// Given two numbers represented as strings, return multiplication of the numbers as a string.
// Note: The numbers can be arbitrarily large and are non-negative.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string multiply(string num1, string num2) {
            if (num1.compare("0") == 0 || num2.compare("0") == 0)   // be careful about the logic, if not excluded 0 cases, will be wrong
            {
                return "0";
            }

            int l1 = num1.length();
            int l2 = num2.length();
            string result(l1+l2, '0');
            for (int i = l1-1; i >= 0; i--)
            {
                int carry = 0;
                for (int j = l2-1; j >= 0; j--)
                {
                    int digit = (result[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0') + carry;
                    result[i+j+1] = digit % 10 + '0';
                    carry = digit / 10;
                }
                if (carry > 0)
                {
                    result[i] += carry;
                }
            }
            return (result[0] == '0' ? result.substr(1) : result);
        }
};

int main()
{
    string num1 = "98";
    string num2 = "9";

    Solution solu;
    cout << num1 << " x " << num2 << " = " << solu.multiply(num1, num2) << endl;

    return 0;
}
