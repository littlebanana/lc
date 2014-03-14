// Determine whether an integer is a palindrome. Do this without extra space.
// Some hints:
// Could negative integers be palindromes? (ie, -1)
// If you are thinking of converting the integer to string, note the restriction of using extra space.
// You could also try reversing an integer.
// However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow.
// How would you handle such case?
// There is a more generic way of solving this problem.

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0)
            {
                return false;
            }
            if (x < 10)
            {
                return true;
            }

            int l = 0;
            int tmp = x;
            while (tmp != 0)
            {
                l++;
                tmp /= 10;
            }

            int pow10 = pow(10,l-1);
            for (int i = 0; i < l/2; i++)
            {
                int msb = x / pow10;
                int lsb = x % 10;
                if (msb != lsb)
                {
                    return false;
                }
                x %= pow10;
                x /= 10;
                pow10 /= 100;
            }
            return true;
        }
};

int main()
{
    Solution solu;

    int x = 1001;
    cout << "x = " << x << ", isPalindrome? " << (solu.isPalindrome(x) ? "yes" : "no") << endl;
    x = -1001;
    cout << "x = " << x << ", isPalindrome? " << (solu.isPalindrome(x) ? "yes" : "no") << endl;

    return 0;
}
