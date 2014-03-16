// Given a non-negative number represented as an array of digits, plus one to the number.
// The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int carry = 1;
            int n = digits.size();
            vector<int> result(n+1);
            for (int i = n-1; i >= 0; i--)
            {
                int d = carry + digits[i];
                result[i+1] = d % 10;
                carry = (d >= 10 ? 1 : 0);
            }
            if (carry > 0)
            {
                result[0] = 1;
            }
            else
            {
                result.erase(result.begin());
            }
            return result;
        }
};

int main()
{
    int A[] = {9, 9, 9};
    vector<int> num(A, A+3);

    Solution solu;
    vector<int> result = solu.plusOne(num);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;

    return 0;
}
