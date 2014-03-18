// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 

#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        int trap(int A[], int n) {
            int sum = 0;
            stack<int> stk;
            for (int i = 0; i < n; i++)
            {
                if (stk.empty() || A[stk.top()] > A[i])
                {
                    stk.push(i);
                }
                else    // only when a higher bar appears, rain can be trapped
                {
                    int bottom = A[stk.top()];  // bottom of the bucket
                    stk.pop();
                    sum += (stk.empty() ? 0 : (i-stk.top()-1)*(min(A[stk.top()], A[i])-bottom));
                    i--;
                }
            }
            return sum;
        }
};

int main()
{
    int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    Solution solu;
    cout << solu.trap(A, 12) << endl;

    return 0;
}
