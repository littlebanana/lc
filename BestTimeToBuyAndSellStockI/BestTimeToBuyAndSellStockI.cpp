// Say you have an array for which the ith element is the price of a given stock on day i.
// If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

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
        int low = prices[0];
        for (int i = 1; i < n; i++)
        {
            profit = max(profit, prices[i]-low);    // reject any lower profit
            low = min(low, prices[i]);              // update the lowest point ever seen
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
