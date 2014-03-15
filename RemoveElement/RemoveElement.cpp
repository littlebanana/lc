// Given an array and a value, remove all instances of that value in place and return the new length.
// The order of elements can be changed.
// It doesn't matter what you leave beyond the new length. 

#include <iostream>

using namespace std;

class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            for (int i = 0; i < n; i++)
            {
                if (A[i] == elem)
                {
                    swap(A[i--], A[--n]);
                }
            }
            return n;
        }
};

int main()
{
    int A[] = {1, 1, 1};

    Solution solu;
    int n = solu.removeElement(A, 3, 1);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

    int B[] = {1, 2, 2, 1, 1, 4};
    n = solu.removeElement(B, 6, 1);
    for (int i = 0; i < n; i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
