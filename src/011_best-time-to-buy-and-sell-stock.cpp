///////////////////////////////////////////////
/// @file 011_best-time-to-buy-and-sell-stock.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/// @version 0.1
/// @date 2022-01-10
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////

#include <vector>
#include <cstdio>
#include <assert.h>

using namespace std;

// Runtime: 266 ms, faster than 5.11% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.3 MB, less than 90.05% of C++ online submissions for Best Time to Buy and Sell Stock.

class Solution
{
public:
    ///////////////////////////////////////////////
    /// @brief You are given an array prices where prices[i] is the price of a given stock on the ith day.
    ///        You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    ///        Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
    ///
    /// @param prices
    /// @return int
    ///////////////////////////////////////////////
    int maxProfit(vector<int> &prices)
    {
        int min = prices[0];
        int best_price = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - min > best_price)

                best_price = prices[i] - min;

            if (prices[i] < min)
                min = prices[i];
        }
        return best_price;
    }
};

bool tests(Solution &solution)
{
    // Example 1:
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    // Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    assert(solution.maxProfit(prices1) == 5);

    // Example 2:

    // Input: prices = [7,6,4,3,1]
    // Output: 0
    // Explanation: In this case, no transactions are done and the max profit = 0.
    vector<int> prices2 = {7, 6, 4, 3, 1};
    assert(solution.maxProfit(prices2) == 0);

    return true;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    if (tests(solution))
        printf("PASS!\n");
    else
        printf("FAIL!\n");
    return 0;
}
