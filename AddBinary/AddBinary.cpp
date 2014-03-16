// Given two binary strings, return their sum (also a binary string).
// For example,
// a = "11"
// b = "1"
// Return "100". 

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            if (a.length() < b.length())
            {
                swap(a, b);
            }

            int la = a.length();
            int lb = b.length();

            int carry = 0;
            string result = a;
            cout << result << endl;
            for (int i = 0; i < lb; i++)
            {
                int digit = (result[la-1-i]-'0') + (b[lb-1-i]-'0') + carry;

                result[la-1-i] = digit % 2 + '0';
                carry = (digit >= 2 ? 1 : 0);
            }
            cout << result << endl;
            for (int i = la-1-lb; i >= 0; i--)
            {
                cout << "i = " <<i <<endl;
                int digit = (result[i]-'0') + carry;
                cout << "digit = " <<digit << endl;

                result[i] = digit % 2 + '0';

                cout << result << endl;
                carry = (digit >= 2 ? 1 : 0);
                cout << "carry = " << carry <<endl;
                if (carry == 0)
                {
                    break;
                }
            }
            return (carry > 0 ? "1"+result : result);
        }

        string addBinary2(string a, string b) {
            if (a.length() < b.length())
            {
                swap(a, b);
            }

            string sum = a;
            int la = a.length();
            int lb = b.length();
            int carry = 0;
            for (int i = 0; i < lb; i++)
            {
                int d = (sum[la-1-i]-'0') + (b[lb-1-i]-'0') + carry;
                sum[la-1-i] = d % 2 + '0';
                carry = (d >= 2 ? 1 : 0);
            }
            for (int i = lb; i < la && carry > 0; i++)
            {
                int d = (sum[la-1-i]-'0') + carry;
                sum[la-1-i] = d % 2 + '0';
                carry = (d >= 2 ? 1 : 0);
            }
            return (carry > 0 ? "1"+sum : sum);
        }
};

int main()
{
    string a = "11";
    string b = "1";

    Solution solu;
    cout << solu.addBinary(a, b) << endl;

    return 0;
}
