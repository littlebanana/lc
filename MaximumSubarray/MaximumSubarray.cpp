// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
// For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4],
// the contiguous subarray [4, -1, 2, 1] has the largest sum = 6.
// More practice:
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    public:
        int maxSubArray1(int A[], int n) {
            int sum = 0;        // sum[i] = A[0] + .. + A[i]
            int minsum = 0;     // minsum[i] = min_{-1<=j<i}sum[j]
            int maxsum = A[0];
            for (int i = 0; i < n; i++) {
                sum += A[i];
                maxsum = max(maxsum, sum-minsum);
                minsum = min(minsum, sum);
            }
            return maxsum;
        }

        int maxSub(int A[], int left, int right) {
            if (left == right) {
                return A[left];
            }
            if (left+1 == right) {
                int m = max(A[left], A[right]);
                return max(m, A[left]+A[right]);
            }

            // divide
            int mid = left + (right-left)/2;
            int lmax = maxSub(A, left, mid-1);
            int rmax = maxSub(A, mid+1, right);
            int m = max(lmax, rmax);

            // combine
            int mmax = A[mid];
            int sum = mmax;
            for (int i = mid-1; i >= left; i--) {
                sum += A[i];
                mmax = max(mmax, sum);
            }
            sum = mmax;
            for (int i = mid+1; i <= right; i++) {
                sum += A[i];
                mmax = max(mmax, sum);
            }

            return max(m, mmax);
        }

        int maxSubArray2(int A[], int n) {
            assert(n > 0);
            return maxSub(A, 0, n-1);
        }
};

int main() {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution solu;
    cout << solu.maxSubArray2(A, 9) << endl;

    return 0;
}
