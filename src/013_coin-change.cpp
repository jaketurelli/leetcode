///////////////////////////////////////////////
/// @file 013_coin-change.cpp
/// @author Jake Turelli (jake.turelli@gmail.com)
/// @brief https://leetcode.com/problems/coin-change/
/// @version 0.1
/// @date 2022-01-11
///
/// @copyright Copyright (c) 2022
///
///////////////////////////////////////////////
#include <vector>
#include <assert.h>
#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
private:
    static constexpr int MIN_START = 10 * 10 * 10 * 10 + 1;
    int m_min;
    bool m_min_found;

public:
    ///////////////////////////////////////////////
    /// @brief You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
    /// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
    /// You may assume that you have an infinite number of each kind of coin.
    ///
    /// @param coins
    /// @param amount
    /// @return int
    ///////////////////////////////////////////////
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> sorted_coins = coins;
        sort(sorted_coins.begin(), sorted_coins.end(), greater<int>());
        m_min = MIN_START;
        m_min_found = false;

        increment_value(sorted_coins, amount, 0);
        return m_min == MIN_START ? -1 : m_min;
    }

private:
    int increment_value(vector<int> &coins, int current_amount, int number_coins)
    {
        if (current_amount < 0 || number_coins < 0)
            return -1;

        if (current_amount == 0)
        {
            if (number_coins < m_min)
            {
                m_min = number_coins;
                m_min_found = true;
                printf("min number coins: %i\n", number_coins);
            }
            return number_coins;
        }

        for (auto i = coins.begin(); i != coins.end(); ++i)
        {
            int curr_number_coins = number_coins - current_amount / *i;
            int curr_amount = current_amount % *i;

            increment_value(coins, curr_amount, curr_number_coins);
            if (m_min_found)
                return 0;
        }
        return 0;
    }
};

bool tests(Solution &solution)
{
    // Example 1:
    // Input: coins = [1,2,5], amount = 11
    // Output: 3
    // Explanation: 11 = 5 + 5 + 1
    vector<int> test1_coins = {1, 2, 5};
    int test1_amount = 11;
    assert(solution.coinChange(test1_coins, test1_amount) == 3);

    // Example 2:
    // Input: coins = [2], amount = 3
    // Output: -1
    vector<int> test2_coins = {2};
    int test2_amount = 3;
    assert(solution.coinChange(test2_coins, test2_amount) == -1);

    // Example 3:
    // Input: coins = [1], amount = 0
    // Output: 0
    vector<int> test3_coins = {1};
    int test3_amount = 0;
    assert(solution.coinChange(test3_coins, test3_amount) == 0);

    // Test 4
    // [ 1, 3, 5 ]
    // 5
    vector<int> test4_coins = {1, 3, 5};
    int test4_amount = 5;
    assert(solution.coinChange(test4_coins, test4_amount) == 1);

    // Test 5
    vector<int> test5_coins = {3, 5};
    int test5_amount = 9;
    assert(solution.coinChange(test5_coins, test5_amount) == 3);

    // TEst 6
    vector<int> test6_coins = {1, 2, 5};
    int test6_amount = 100;
    printf("%i\n", solution.coinChange(test6_coins, test6_amount));
    assert(solution.coinChange(test6_coins, test6_amount) == 20);

    // TEst 7
    vector<int> test7_coins = {186, 419, 83, 408};
    int test7_amount = 6249;
    printf("%i\n", solution.coinChange(test7_coins, test7_amount));
    assert(solution.coinChange(test7_coins, test7_amount) == 20);

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