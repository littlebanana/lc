// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> leftProfit(const vector<int> &prices)
        {
            int n = prices.size();
            vector<int> left(n);
            left[0] = 0;
            int low = prices[0];
            for (int i = 1; i < n; i++)
            {
                left[i] = max(left[i-1], prices[i]-low);
                low = min(low, prices[i]);
            }
            return left;
        }

        vector<int> rightProfit(const vector<int> &prices)
        {
            int n = prices.size();
            vector<int> right(n);
            right[n-1] = 0;
            int high = prices[n-1];
            for (int i = n-2; i >= 0; i--)
            {
                right[i] = max(right[i+1], high-prices[i]);
                high = max(high, prices[i]);
            }
            return right;
        }

        int maxProfit(vector<int> &prices) {
            int n = prices.size();
            if (n < 2)
            {
                return 0;
            }
            vector<int> left = leftProfit(prices);
            vector<int> right = rightProfit(prices);

            int profit = left[n-1];     // one-transcation profit
            for (int i = 0; i < n-1; i++)
            {
                profit = max(profit, left[i]+right[i+1]);
            }
            return profit;
        }

        // optimized, eliminate O(N) space
        int maxProfit2(vector<int> &prices)
        {
            int n = prices.size();
            if (n < 2)
            {
                return 0;
            }

            vector<int> left = leftProfit(prices);

            int profit = left[n-1];     // one-transcation profit
            int right = 0;
            int high = prices[n-1];
            for (int i = n-1; i > 0; i--)
            {
                right = max(right, high-prices[i]);
                profit = max(profit, left[i-1]+right);
                high = max(high, prices[i]);
            }
            return profit;
        }

        // Dynamic Programming
        // 
        // f[i][j] is the max sum of j segments ended with diff[i]
        // Thus:
        //              |- f[i - 1][j] + diff[i] # append diff[i] to j segments
        // f[i][j] = max|
        //              |- max{f[k][j - 1], k in [0, i - 1]} + diff[i] # new segment from diff[i]
        //
        // Store the max{...} in g[i - 1][j - 1], then we can access the max in O(1) time
        // TODO
        int maxProfit3(vector<int> &prices) {
            int f[3] = {0};
            int g[3] = {0};

            int n = prices.size() - 1;
            for (int i = 0; i < n; ++i) {
                int diff = prices[i+1] - prices[i];
                int m = min(i+1, 2);
                for (int j = m; j >= 1; --j) {
                    f[j] = max(f[j], g[j-1]) + diff;
                    g[j] = max(g[j], f[j]);
                }
            }
            return max(g[1], g[2]);
        }
};

int main()
{
    int A[] = {3, 2, 1, 4, 5, 3, 2, 7};
    vector<int> prices(A, A+8);

    Solution solu;
    cout << solu.maxProfit(prices) << endl;

    return 0;
}
