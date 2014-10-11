// Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
// Do not allocate extra space for another array, you must do this in place with constant memory.
// For example, given input array A = [1,1,2],
// your function should return length = 2, and A is now [1,2]. 

#include <iostream>
#include <algorithm>    // swap

using namespace std;

class Solution {
    public:
        // test case: 1, 1, 1, 2, 2, 3
        int removeDuplicates(int A[], int n) {
            if (n == 0) {
                return 0;
            }

            int ok = 0;     // last index of the array which is sorted and without duplicates
            for (int i = 1; i < n; i++) {
                if (A[ok] != A[i]) {
                    swap(A[++ok], A[i]);
                }
            }
            return ok+1;
        }
};

int main() {
    int A[] = {1, 1, 1, 2, 2, 3};

    Solution solu;
    int n = solu.removeDuplicates(A, 6);

    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
