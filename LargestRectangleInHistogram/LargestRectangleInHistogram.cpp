#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            int L = height.size();
            if (L == 0)
            {
                return 0;
            }

            // basic idea:
            // find the maximal rectangles which contain each individual bar
            // use stack to track the incoming orders

            height.push_back(0);        // dummy end, ensure all rectangles with contain positive bar get popped

            int maxarea = height[0];
            stack<int> stk;
            for (int i = 0; i < L+1; i++)
            {
                if (stk.empty() || height[i] >= height[stk.top()])
                {
                    stk.push(i);
                }
                else
                {
                    int h = height[stk.top()];
                    stk.pop();
                    int area = h*((stk.empty()) ? i : (i-stk.top()-1));
                    maxarea = max(area, maxarea);
                    i--;
                }
            }
            height.pop_back();
            return maxarea;
        }
};

int main()
{
    vector<int> histogram(6);
    histogram[0] = 2;
    histogram[1] = 1;
    histogram[2] = 5;
    histogram[3] = 6;
    histogram[4] = 2;
    histogram[5] = 3;

    Solution solu;
    cout << solu.largestRectangleArea(histogram) << endl;

    return 0;
}
