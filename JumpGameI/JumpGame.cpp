// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
// For example:
// A = [2,3,1,1,4], return true.
// A = [3,2,1,0,4], return false. 

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
        bool canJump(int A[], int n) {
            int far = 0;        // the farest element can be reached
            for (int i = 0; i < n; i++)
            {
                if (i > far)
                {
                    return false;
                }
                else
                {
                    far = max(far, A[i]+i);
                    if (far >= n)
                    {
                        return true;
                    }
                }
            }
            return true;
        }
};

int main()
{
    Solution solu;

    int A[5] = {2, 3, 1, 1 ,4};
    cout << (solu.canJump(A, 5) ? "true" : "false") << endl;

    int B[5] = {3, 2, 1, 0, 4};
    cout << (solu.canJump(B, 5) ? "true" : "false") << endl;

    return 0;
}
