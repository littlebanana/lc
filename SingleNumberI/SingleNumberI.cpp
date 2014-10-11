// Given an array of integers, every element appears twice except for one. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 

#include <iostream>

using namespace std;

class Solution
{
    public:
        int singleNumber(int A[], int n) {
            int single = 0;
            for (int i = 0; i < n; i++) {
                single ^= A[i];
            }
            return single;
        }
};

int main() {
    int A[] ={1, 1, 2, 2, 3, 3, 6, 6, 5};

    Solution solu;
    cout << solu.singleNumber(A, 9) << endl;

    return 0;
}
