// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
// For example,
// Given sorted array A = [1,1,1,2,2,3],
// Your function should return length = 5, and A is now [1,1,2,2,3]. 

#include <iostream>

using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            if (n < 3) {
                return n;
            }

            int sorted = 0;
            int cnt = 1;
            for (int i = 1; i < n; i++) {
                if (A[i] != A[sorted]) {
                    swap(A[++sorted], A[i]);
                    cnt = 1;
                } else if (A[i] == A[sorted] && cnt == 1) {
                    swap(A[++sorted], A[i]);
                    cnt++;
                } 
            }
            return (sorted + 1);
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
    int n = 6;
    int A[] = {1, 1, 1, 2, 2, 3};
    printArray(A, n);

    Solution solu;
    n = solu.removeDuplicates(A, n);
    printArray(A, n);

    return 0;
}
