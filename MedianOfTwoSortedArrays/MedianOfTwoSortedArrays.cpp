#include <iostream>	    // cout
#include <algorithm>	// min

using namespace std;

class Solution
{
    public:
        // Approach 1
        double findKthElementSortedArrays(int A[], int m, int B[], int n, int k)
        {
            if (m > n)
            {
                return findKthElementSortedArrays(B, n, A, m, k);
            }
            if (m == 0)
            {
                return B[k-1];
            }
            if (k == 1)
            {
                return min(A[0], B[0]);
            }

            int ma = min(m, k/2);
            int na = k - ma;
            if (A[ma-1] == B[na-1])
            {
                return A[ma-1];
            }
            else if (A[ma-1] > B[na-1])
            {
                return findKthElementSortedArrays(A, m, B+na, n-na, k-na);
            }
            else
            {
                return findKthElementSortedArrays(A+ma, m-ma, B, n, k-ma);
            }
        }

        // Approach 2: Compare two medians
        // TODO

        double findMedianSortedArrays(int A[], int m, int B[], int n)
        {
            if ((m + n) % 2 == 0)
            {
                return (findKthElementSortedArrays(A, m, B, n, (m+n)/2) + findKthElementSortedArrays(A, m, B, n, (m+n)/2+1))/2.0;
            }
            else
            {
                return findKthElementSortedArrays(A, m, B, n, (m+n)/2+1);
            }
        };
};

void printArray(int A[], int n)
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i != n-1)
        {
            cout << ", ";
        }
    }
    cout << "]";
}

int main()
{
    int A[] = {1, 3, 4, 7, 9};
    int B[] = {2, 2, 3, 3};

    Solution solu;

    cout << "A = ";
    printArray(A, 5);
    cout << endl;
    cout << "B = ";
    printArray(B, 4);
    cout << endl;
    cout << "Median = " << solu.findMedianSortedArrays(A, 5, B, 4) << endl;

    return 0;
}
