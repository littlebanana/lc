// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// For example:
// Given array A = [2,3,1,1,4]
// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 

#include <iostream>
#include <cassert>

using namespace std;

class Solution {
    public:
        int jump(int A[], int n) {
            assert(n > 0);
            int step = 0;
            int thisstep = 0;       // the farthest idx can be reached in current step
            int nextstep = 0;       // the farthest idx can be reached in the next step, keep updating while run through the array
            for (int i = 0; i < n; i++) {
                if (i > thisstep) {
                    if (i > nextstep) {
                        return -1;
                    }
                    step++;
                    thisstep = nextstep;
                    if (thisstep >= n-1) {
                        return step;
                    }
                    nextstep = i + A[i];
                } else {
                    nextstep = max(nextstep, i+A[i]);
                }
            }
            return step;
        }
};

int main() {
    int A[5] = {2, 3, 1, 1, 4};

    Solution solu;
    cout << solu.jump(A, 5) << endl;

    return 0;
}
