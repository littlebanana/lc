// The set [1,2,3,бн,n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// We get the following sequence (ie, for n = 3):
//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"
// Given n and k, return the kth permutation sequence.
// Note: Given n will be between 1 and 9 inclusive.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string getPermutation(int n, int k) {
            string s(n, '1');
            int fact = 1;
            for (int i = 1; i < n; i++)
            {
                s[i] += i;
                fact *= i;
            }

            int i = 0;
            while (k > 1)
            {
                int idx = (k-1) / fact;     // relative offset
                char tmp = s[i+idx];
                for (int j = i+idx-1; j >= i; j--)
                {
                    s[j+1] = s[j];
                }
                s[i] = tmp;

                k -= idx*fact;
                fact /= (n-i-1);
                i++;
            }
            return s;
        }
};

int main()
{
    Solution solu;
    string s = solu.getPermutation(5, 37);

    cout << s << endl;

    return 0;
}
