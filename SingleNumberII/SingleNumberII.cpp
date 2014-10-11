// Given an array of integers, every element appears three times except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

#include <iostream>

using namespace std;

class Solution {
    public:
        // ATTENTION: Always add parentheses embracing the bitwise operation before the boolean testing!!
        // a & b != 0   -----> WRONG, equalvent to a & (b != 0)
        // (a & b) != 0 -----> CORRECT
        int singleNumber1(int A[], int n) {
            int ones = 0;
            int twos = 0;
            for (int i = 0; i < n; i++) {
                twos |= (ones & A[i]);
                ones ^= A[i];
                // if at anny digit, both twos and ones are set,
                // meaning 3 multiple of the binary representation of that digit in the current sum
                // need to clear both twos and ones at that digit
                int threes = ~(ones & twos);
                ones &= threes;
                twos &= threes;
            }
            return ones;
        }

        int singleNumber2(int A[], int n) {
            int ones = 0;
            int twos = 0;

            // use truth table to simplify boolean expression
            // for ones:
            // A[i] | ones | twos | output
            //   0      0      0      0
            //   0      0      1      0
            //   0      1      0      1
            //   0      1      1      0  (clear bit)
            //   1      0      0      1
            //   1      0      1      0
            //   1      1      0      0
            //   1      1      1      0  (impossible, ones and twos not 1 at the same time)
            // to simplify expression, focus on the truth cases
            // output = (~A[i] & ones & ~twos) | (A[i] & ~ones & ~twos)
            //        = ~A[i]*ones*~twos + A[i]*~ones*~twos
            //        =  (~A[i]*ones + A[i]*~ones)*~twos
            //        = (A[i] ^ ones) & ~twos
            // for twos:
            // A[i] | ones | twos | output
            //   0      0      0      0
            //   0      0      1      1
            //   0      1      0      0
            //   0      1      1      0  (clear bit)
            //   1      0      0      0
            //   1      0      1      0
            //   1      1      0      1
            //   1      1      1      x  (impossible, ones and twos not 1 at the same time)
            // output = (~A[i] & ~ones & twos) | (A[i] & ones & ~twos)
            //        = ~A[i]*~ones*twos + A[i]*ones*~twos
            //        = A[i]*ones ^ twos

            for (int i = 0; i < n; i++) {
                int ones_ = (A[i] ^ ones) & ~twos;
                int twos_ = (~A[i] & ~ones & twos) | (A[i] & ones & ~twos);
                ones = ones_;
                twos = twos_;
            }
            return ones;
        }

        int singleNumber3(int A[], int n) {
            const int l = 8 * sizeof(int);    // convert number of bytes to bits
            int cnt[l];
            // cnt[0...(l-1)]: LSB -> MSB
            for (int j = 0; j < l; j++) {
                cnt[j] = 0;
            }

            int single = 0;
            for (int j = 0; j < l; j++) {
                for (int i = 0; i < n; i++) {
                    cnt[j] += (A[i] >> j) & 1;
                }
                cnt[j] %= 3;
                single += (cnt[j] << j);
            }
            return single;
        }

        // clear verison using boolean algebra, un-simpified expression
        int singleNumber4(int A[], int n) {
            // ones = 1 when (ones, twos, A[i]) = (1,0,0) OR (0,0,1)
            // twos = 1 when (ones, twos, A[i]) = (1,0,1) OR (0,1,0)
            int ones = 0;
            int twos = 0;
            for (int i = 0; i < n; i++) {
                int ones_ = ((ones & ~twos & ~A[i]) | (~ones & ~twos & A[i]));
                int twos_ = ((ones & ~twos & A[i]) | (~ones & twos & ~A[i]));
                ones = ones_;
                twos = twos_;
            }
            return ones;
        }
};

int main() {
    // int A[] = {1, 1, 1, 2, 4, 4, 4, 3, 3, 3};
    int A[] = {0, 1, 0, 1, 0, 1, 99};

    Solution solu;
    cout << solu.singleNumber3(A, 7) << endl;

    return 0;
}
