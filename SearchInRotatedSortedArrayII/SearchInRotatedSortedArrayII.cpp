// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?
// Write a function to determine if a given target is in the array.

#include <iostream>

using namespace std;

class Solution {
    public:
        // Complexity: O(N) worse case
        bool binarySearch(int A[], int left, int right, const int target)
        {
            if (left > right)
            {
                return false;
            }

            int mid = left + (right-left)/2;
            if (target == A[mid] || target == A[left] || target == A[right])
            {
                return true;
            }
            if (A[left] < A[mid])
            {
                if (target > A[left] && target < A[mid])
                {
                    return binarySearch(A, left+1, mid-1, target);
                }
                else
                {
                    return binarySearch(A, mid+1, right-1, target);
                }
            }
            else if (A[mid] < A[right])
            {
                if (target > A[mid] && target < A[right])
                {
                    return binarySearch(A, mid+1, right-1, target);
                }
                else
                {
                    return binarySearch(A, left+1, mid-1, target);
                }
            }
            return (binarySearch(A, left+1, mid-1, target) || binarySearch(A, mid+1, right-1, target));
        }

        bool search1(int A[], int n, int target) {
            return binarySearch(A, 0, n-1, target);
        }
        // iterative approach
        bool search2(int A[], int n, int target) {
            int p = 0;
            int q = n-1;
            while (p <= q)
            {
                int m = p + (q-p)/2;
                if (target == A[m] || target == A[p] || target == A[q])
                {
                    return true;
                }
                if (A[p] < A[m])
                {
                    if (target > A[p] && target < A[m])
                    {
                        q = m-1;
                    }
                    else
                    {
                        p = m+1;
                    }
                }
                else if (A[m] < A[q])
                {
                    if (target > A[m] && target < A[q])
                    {
                        p = m+1;
                    }
                    else
                    {
                        q = m-1;
                    }
                }
                else    // must be the case when A[p] == A[m] == A[q]
                {
                    p++;
                    q--;
                }
            }
            return false;
        }
};

int main()
{
    int A[] = {1, 2, 3, 1, 1, 1};

    Solution solu;
    cout << solu.search1(A, 6, 2) << endl;
    cout << solu.search1(A, 6, 4) << endl;

    return 0;
}
