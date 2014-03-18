// Given an unsorted integer array, find the first missing positive integer.
// For example,
// Given [1,2,0] return 3, and [3,4,-1,1] return 2.
// Your algorithm should run in O(n) time and uses constant space. 

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // O(N): one swap makes one element in the correct position
        //       no need to enter while loop for that element after that
        for (int i = 0; i < n; i++)
        {
            while (A[i] > 0 && A[i] <= n && A[i] != i+1 && A[A[i]-1] != A[i])
            {
                swap(A[i], A[A[i]-1]);
            }
        }
        int idx = 0;
        for (; idx < n && A[idx] == idx+1; idx++);
        return idx+1;
    }
};

int main()
{
    int A[] = {3, 2, 0, 5, 1};

    Solution solu;
    cout << solu.firstMissingPositive(A, 5) << endl;

    return 0;
}
