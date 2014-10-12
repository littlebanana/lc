// Find the contiguous subarray within an array (containing at least one number) which has the largest product.  
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.

#include <iostream>

using namespace std;

class Solution {
    public:
        int maxProduct(int A[], int n) {
            int maxSoFar = A[0];    // max subarray product ended at i
            int minSoFar = A[0];    // min subarray product ended at i
            int mm = maxSoFar;
            for (int i = 1; i < n; i++) {
                if (A[i] > 0) {
                    maxSoFar = max(maxSoFar * A[i], A[i]);
                    minSoFar = min(minSoFar * A[i], A[i]);
                } else if (A[i] == 0) {
                    maxSoFar = 0;
                    minSoFar = 0;
                } else {
                    int tmp = max(minSoFar * A[i], A[i]);
                    minSoFar = min(maxSoFar * A[i], A[i]);
                    maxSoFar = tmp;
                }
                mm = max(maxSoFar, mm);
            }
            return mm;
        }
};

int main() {
    int A[] = {2, 3, -2, 4};
    Solution solu;
    cout << solu.maxProduct(A, 4) << endl;

    return 0;
}
