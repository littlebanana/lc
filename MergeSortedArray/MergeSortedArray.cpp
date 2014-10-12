// Given two sorted integer arrays A and B, merge B into A as one sorted array.
// Note:
// You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B.
// The number of elements initialized in A and B are m and n respectively.

#include <iostream>

using namespace std;

class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            int t = m + n - 1;
            int p = m - 1;
            int q = n - 1;
            while (p >= 0 && q >= 0) {
                if (A[p] >= B[q]) {
                    A[t--] = A[p--];
                } else {
                    A[t--] = B[q--];
                }
            }
            while (q >= 0) {
                A[t--] = B[q--];
            }
        }
};

void printArray(int A[], int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i < n-1) {
            cout << " ";
        }
    }
    cout << "]" << endl;
}

int main() {
    int A[] = {1, 1, 3, 4, 7, 0, 0, 0, 0};
    int B[] = {1, 4, 5, 9};

    printArray(A, 5);
    printArray(B, 4);

    Solution solu;
    solu.merge(A, 5, B, 4);

    printArray(A, 9);

    return 0;
}
