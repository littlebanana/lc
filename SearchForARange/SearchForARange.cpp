// Given a sorted array of integers, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].
// For example, given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4]. 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int searchLeft(int A[], int left, int right, const int target)
        {
            if (left > right)
            {
                return -1;
            }

            int mid = left + (right-left)/2;
            if (target == A[mid])
            {
                int l = searchLeft(A, left, mid-1, target);
                return (l == -1 ? mid : l);
            }
            else if (target < A[mid])
            {
                return searchLeft(A, left, mid-1, target);
            }
            else
            {
                return searchLeft(A, mid+1, right, target);
            }
        }

        int searchRight(int A[], int left, int right, const int target)
        {
            if (left > right)
            {
                return -1;
            }

            int mid = left + (right-left)/2;
            if (target == A[mid])
            {
                int r = searchRight(A, mid+1, right, target);
                return (r == -1 ? mid : r);
            }
            else if (target < A[mid])
            {
                return searchRight(A, left, mid-1, target);
            }
            else
            {
                return searchRight(A, mid+1, right, target);
            }
        }

        vector<int> searchRange1(int A[], int n, int target) {
            vector<int> idx(2);
            idx[0] = searchLeft(A, 0, n-1, target);
            idx[1] = searchRight(A, 0, n-1, target);
            return idx;
        }

        // iterative
        vector<int> searchRange2(int A[], int n, int target) {
            int p = 0;
            int q = n-1;

            int left = -1;
            while (p <= q)
            {
                int m = p + (q-p)/2;
                if (A[m] >= target)
                {
                    if (A[m] == target)
                    {
                        left = m;
                    }
                    q = m-1;
                }
                else
                {
                    p = m+1;
                }
            }

            int right = -1;
            p = 0;
            q = n-1;
            while (p <= q)
            {
                int m = p + (q-p)/2;
                if (A[m] <= target)
                {
                    if (A[m] == target)
                    {
                        right = m;
                    }
                    p = m+1;
                }
                else
                {
                    q = m-1;
                }
            }

            vector<int> idx(2);
            idx[0] = left;
            idx[1] = right;
            return idx;
        }
};

int main()
{
    int A[] = {5, 7, 7, 7, 8, 10};

    Solution solu;
    vector<int> idx = solu.searchRange1(A, 6, 7);

    cout << idx[0] << " " << idx[1] << endl;

    return 0;
}
