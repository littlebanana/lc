// Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
// Note:
// You are not suppose to use the library's sort function for this problem.
// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting sort.
// First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
// Could you come up with an one-pass algorithm using only constant space?

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void sortColors(int A[], int n) {
            // Dutch Flag Partition
            int red = -1;
            int blue = n;
            for (int i = 0; i < blue; i++) {
                if (A[i] == 0) {
                    swap(A[i], A[++red]);
                } else if (A[i] == 2) {
                    swap(A[i--], A[--blue]);    // remember to decrement i for a double check at same location next iteration
                }
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
    int A[] = {0, 1, 1, 2, 0, 2, 1, 1, 0, 2};
    printArray(A, 10);

    Solution solu;
    solu.sortColors(A, 10);

    printArray(A, 10);

    return 0;
}
