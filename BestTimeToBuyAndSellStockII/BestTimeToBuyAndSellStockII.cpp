// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
// However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2)
        {
            return 0;
        }
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            profit += max(0, prices[i]-prices[i-1]);    // catch any profitable opportunities
        }
        return profit;
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