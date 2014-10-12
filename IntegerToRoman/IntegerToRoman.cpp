// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        string intToRoman(int num) {
            char tab[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
            string roman;
            int i = 0;
            int pow10 = 10*10*10;
            while (num != 0) {
                int digit = num / pow10;

                if (digit < 4) {
                    roman.append(digit, tab[i]);
                } else if (digit == 4) {
                    roman += tab[i];
                    roman += tab[i-1];
                } else if (digit == 5) {
                    roman += tab[i-1];
                } else if (digit < 9) {
                    roman += tab[i-1];
                    roman.append(digit-5, tab[i]);
                } else {
                    roman += tab[i];
                    roman += tab[i-2];
                }

                i += 2;
                num %= pow10;
                pow10 /= 10;
            }
            return roman;
        }

        string intToRoman2(int num) {
            // I - 1, V - 5, X - 10, L - 50, C - 100, D - 500, M - 1000
            string symbs[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            string roman;
            for (int i = 0; i < 13; i++) {
                while (num >= nums[i]) {
                    roman += symbs[i];
                    num -= nums[i];
                }
            }
            return roman;
        }
};

int main() {
    Solution solu;

    int x = 1024;
    cout << "x = " << x << ", roman = " << solu.intToRoman(x) << endl;

    return 0;
}
