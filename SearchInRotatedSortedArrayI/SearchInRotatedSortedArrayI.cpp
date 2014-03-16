// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search.
// If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.

#include <iostream>

using namespace std;

class Solution {
    public:
        int binarySearch(int A[], int left, int right, const int target)
        {
            if (left > right)
            {
                return -1;
            }

            int mid = left + (right-left)/2;
            if (A[mid] == target)
            {
                return mid;
            }
            if (A[left] == target)
            {
                return left;
            }
            if (A[right] == target)
            {
                return right;
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
            else
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
        }

        int search(int A[], int n, int target) {
            return binarySearch(A, 0, n-1, target);
        }

        int search2(int A[], int n, int target) {
            // iterative approach
            int p = 0;
            int q = n-1;
            while (p <= q)
            {
                int m = p + (q-p)/2;
                if (target == A[m])
                {
                    return m;
                }
                if (target == A[p])
                {
                    return p;
                }
                if (target == A[q])
                {
                    return q;
                }

                if (A[p] <= A[m])
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
                else
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
            }
            return -1;
        }
};

int main()
{
    int A[] = {3, 1};

    Solution solu;
    cout << solu.search2(A, 2, 1) << endl;

    return 0;
}
