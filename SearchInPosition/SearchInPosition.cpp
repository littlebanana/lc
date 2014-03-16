// Given a sorted array and a target value, return the index if the target is found.
// If not, return the index where it would be if it were inserted in order.
// You may assume no duplicates in the array.
// Here are few examples.
// [1,3,5,6], 5 -> 2
// [1,3,5,6], 2 -> 1
// [1,3,5,6], 7 -> 4
// [1,3,5,6], 0 -> 0 

#include <iostream>

using namespace std;

class Solution {
    public:
        int binarySearch(int A[], int left, int right, const int target)
        {
            if (left > right)
            {
                return left;
            }

            int mid = left + (right-left)/2;
            if (A[mid] == target)
            {
                return mid;
            }
            else if (A[mid] < target)
            {
                return binarySearch(A, mid+1, right, target);
            }
            else
            {
                return binarySearch(A, left, mid-1, target);
            }
        }

        int searchInsert1(int A[], int n, int target) {
            return binarySearch(A, 0, n-1, target);
        }

        int searchInsert2(int A[], int n, int target) {
            int p = 0;
            int q = n-1;
            while (p <= q)
            {
                int m = p + (q-p)/2;
                if (A[m] == target)
                {
                    return m;
                }
                else if (A[m] < target)
                {
                    p = m+1;
                }
                else
                {
                    q = m-1;
                }
            }
            return p;
        }
};

int main()
{
    int A[] = {1, 3, 5, 6};

    Solution solu;
    cout << solu.searchInsert2(A, 4, 5) << endl;

    return 0;
}
