// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container. 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int n = height.size();
            int p = 0;
            int q = n - 1;
            int maxA = 0;
            while (p < q) {
                int w = q - p;
                int h = (height[p] > height[q] ? height[q--] : height[p++]);
                maxA = max(maxA, h * w);
            }
            return maxA;
        }
};

int main() {
    vector<int> bars;
    bars.push_back(1);
    bars.push_back(4);
    bars.push_back(6);
    bars.push_back(9);
    bars.push_back(3);
    bars.push_back(6);

    Solution solu;
    cout << solu.maxArea(bars) << endl;

    return 0;
}
